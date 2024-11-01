#include <RcppEigen.h>
#include "gradient.h"
#include "utils.h"
#include "variables.h"


Eigen::VectorXd
gradient(const Variables& vars, const Eigen::MatrixXd& Rstar0_inv,
         const Eigen::MatrixXd& S, const Eigen::SparseMatrix<double>& W,
         double lambda, int k)
{
    /* Compute the gradient for cluster k
     *
     * Inputs:
     * vars: struct containing the optimization variables
     * Rstar0_inv: inverse of R* excluding row/column k
     * S: sample covariance matrix
     * W: sparse weight matrix
     * lambda: regularization parameter
     * k: cluster of interest
     *
     * Output:
     * Gradient
     */

    // Create references to the variables in the struct
    const Eigen::MatrixXd &R = vars.m_R;
    const Eigen::MatrixXd &A = vars.m_A;
    const Eigen::VectorXi &p = vars.m_p;
    const Eigen::VectorXi &u = vars.m_u;
    const Eigen::SparseMatrix<double> &D = vars.m_D;

    // Number of clusters
    int n_clusters = R.cols();

    // Number of variables
    int n_variables = S.cols();

    // Initialize result;
    Eigen::VectorXd result(n_clusters + 1);

    // Log determinant part
    Eigen::VectorXd r_k = drop_variable(R.col(k), k);

    // Some temporary variables
    Eigen::VectorXd temp_log_0 = Rstar0_inv * r_k;
    double temp_log_1 = A(k) + (p(k) - 1) * R(k, k);
    temp_log_1 -= p(k) * r_k.dot(temp_log_0);

    // Gradient for A[k]
    result(0) = -1.0 / temp_log_1 - (p(k) - 1) / (A(k) - R(k, k));

    // Gradient for R[k, k]
    result(1 + k) = -(p(k) - 1) / temp_log_1 + (p(k) - 1) / (A(k) - R(k, k));

    // Temporary vector to store gradient of R[k, -k] in
    Eigen::VectorXd grad_r_k = 2 * p(k) / temp_log_1 * temp_log_0;

    // Fill in the gradient for R[k, -k]
    for (int i = 0; i < n_clusters; i++) {
        if (i == k) continue;

        result(1 + i) = grad_r_k(i - (i > k));
    }

    // Covariance part
    // Gradient for A[k]
    double cov_grad_a_kk = partial_trace(S, u, k);
    result(0) += cov_grad_a_kk;

    // Gradient for R[k, k]
    result(1 + k) += sum_selected_elements(S, u, p, k) - cov_grad_a_kk;

    // Gradient for R[k, -k]
    grad_r_k = 2 * sum_multiple_selected_elements(S, u, p, k);

    // Fill in the gradient for R[k, -k]
    for (int i = 0; i < n_clusters; i++) {
        if (i == k) continue;

        result(1 + i) += grad_r_k(i - (i > k));
    }

    // Return if lambda is not positive
    if (lambda <= 0) {
        return result;
    }

    // Clusterpath part
    double grad_a_kk = 0;
    double grad_r_kk = 0;
    grad_r_k = Eigen::VectorXd::Zero(n_clusters);

    // Special case for the kth column
    Eigen::SparseMatrix<double>::InnerIterator D_it(D, k);
    Eigen::SparseMatrix<double>::InnerIterator W_it(W, k);

    for (; W_it; ++W_it) {
        // index
        int l = W_it.row();

        // Compute the inverse of the distance between k and l
        double inv_norm_kl = 1.0 / std::max(D_it.value(), 1e-12);

        // Add to gradients
        grad_a_kk += (A(k) - A(l)) * W_it.value() * inv_norm_kl;
        grad_r_kk +=
            (R(k, k) - R(k, l)) * (p(k) - 1) * W_it.value() * inv_norm_kl;

        for (int m = 0; m < n_clusters; m++) {
            if (m == l) continue;

            grad_r_k(m) +=
                W_it.value() * inv_norm_kl * (R(k, m) - R(m, l)) * p(m);
        }

        double temp = (p(l) - 1) * (R(k, l) - R(l, l));
        temp += (p(k) - 1) * (R(k, l) - R(k, k));
        grad_r_k(l) += temp * inv_norm_kl * W_it.value();

        // Continue iterator for D
        ++D_it;
    }


    for (int m = 0; m < W.outerSize(); m++) {
        if (m == k) continue;

        // Iterators
        Eigen::SparseMatrix<double>::InnerIterator D_it(D, m);
        Eigen::SparseMatrix<double>::InnerIterator W_it(W, m);

        for (; W_it; ++W_it) {
            // index
            int l = W_it.row();

            if (l == k) {
                // Continue iterator for D and skip this iteration
                ++D_it;
                continue;
            }

            // Compute the inverse of the distance between m and l
            double inv_norm_ml = 1.0 / std::max(D_it.value(), 1e-12);

            // Add to the gradient
            grad_r_k(m) +=
                W_it.value() * inv_norm_ml * (R(k, m) - R(k, l)) * p(k);

            // Continue iterator for D
            ++D_it;
        }
    }

    // Add to the complete gradient again
    result(0) += lambda * grad_a_kk;
    result(1 + k) += lambda * grad_r_kk;
    for (int i = 0; i < n_clusters; i++) {
        if (i == k) continue;
        result(1 + i) += lambda * grad_r_k(i);
    }

    return result;
}
