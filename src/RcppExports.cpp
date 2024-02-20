// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// cggm
Rcpp::List cggm(const Eigen::MatrixXd& W_keys, const Eigen::VectorXd& W_values, const Eigen::MatrixXd& Ri, const Eigen::VectorXd& Ai, const Eigen::VectorXi& pi, const Eigen::VectorXi& ui, const Eigen::MatrixXd& S, const Eigen::VectorXd& lambdas, double eps_fusions, double scale_factor, double gss_tol, double conv_tol, int max_iter, bool store_all_res, int verbose);
RcppExport SEXP _CGGMR_cggm(SEXP W_keysSEXP, SEXP W_valuesSEXP, SEXP RiSEXP, SEXP AiSEXP, SEXP piSEXP, SEXP uiSEXP, SEXP SSEXP, SEXP lambdasSEXP, SEXP eps_fusionsSEXP, SEXP scale_factorSEXP, SEXP gss_tolSEXP, SEXP conv_tolSEXP, SEXP max_iterSEXP, SEXP store_all_resSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type W_keys(W_keysSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type W_values(W_valuesSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type Ri(RiSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type Ai(AiSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXi& >::type pi(piSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXi& >::type ui(uiSEXP);
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type S(SSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type lambdas(lambdasSEXP);
    Rcpp::traits::input_parameter< double >::type eps_fusions(eps_fusionsSEXP);
    Rcpp::traits::input_parameter< double >::type scale_factor(scale_factorSEXP);
    Rcpp::traits::input_parameter< double >::type gss_tol(gss_tolSEXP);
    Rcpp::traits::input_parameter< double >::type conv_tol(conv_tolSEXP);
    Rcpp::traits::input_parameter< int >::type max_iter(max_iterSEXP);
    Rcpp::traits::input_parameter< bool >::type store_all_res(store_all_resSEXP);
    Rcpp::traits::input_parameter< int >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(cggm(W_keys, W_values, Ri, Ai, pi, ui, S, lambdas, eps_fusions, scale_factor, gss_tol, conv_tol, max_iter, store_all_res, verbose));
    return rcpp_result_gen;
END_RCPP
}
// count_clusters
int count_clusters(const Eigen::MatrixXi& E, int n);
RcppExport SEXP _CGGMR_count_clusters(SEXP ESEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXi& >::type E(ESEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(count_clusters(E, n));
    return rcpp_result_gen;
END_RCPP
}
// find_subgraphs
Eigen::VectorXi find_subgraphs(const Eigen::MatrixXi& E, int n);
RcppExport SEXP _CGGMR_find_subgraphs(SEXP ESEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXi& >::type E(ESEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(find_subgraphs(E, n));
    return rcpp_result_gen;
END_RCPP
}
// find_mst
Eigen::MatrixXi find_mst(const Eigen::MatrixXd& G);
RcppExport SEXP _CGGMR_find_mst(SEXP GSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type G(GSEXP);
    rcpp_result_gen = Rcpp::wrap(find_mst(G));
    return rcpp_result_gen;
END_RCPP
}
// median_distance
double median_distance(const Eigen::MatrixXd& Theta);
RcppExport SEXP _CGGMR_median_distance(SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type Theta(ThetaSEXP);
    rcpp_result_gen = Rcpp::wrap(median_distance(Theta));
    return rcpp_result_gen;
END_RCPP
}
// k_largest
Eigen::ArrayXi k_largest(const Eigen::VectorXd& vec, int k);
RcppExport SEXP _CGGMR_k_largest(SEXP vecSEXP, SEXP kSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type vec(vecSEXP);
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    rcpp_result_gen = Rcpp::wrap(k_largest(vec, k));
    return rcpp_result_gen;
END_RCPP
}
// compute_Theta
Eigen::MatrixXd compute_Theta(const Eigen::MatrixXd& R, const Eigen::VectorXd& A, const Eigen::VectorXi& u);
RcppExport SEXP _CGGMR_compute_Theta(SEXP RSEXP, SEXP ASEXP, SEXP uSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type R(RSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXi& >::type u(uSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_Theta(R, A, u));
    return rcpp_result_gen;
END_RCPP
}
// scaled_squared_norms
Eigen::MatrixXd scaled_squared_norms(const Eigen::MatrixXd& Theta);
RcppExport SEXP _CGGMR_scaled_squared_norms(SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type Theta(ThetaSEXP);
    rcpp_result_gen = Rcpp::wrap(scaled_squared_norms(Theta));
    return rcpp_result_gen;
END_RCPP
}
// squared_norms
Eigen::MatrixXd squared_norms(const Eigen::MatrixXd& Theta);
RcppExport SEXP _CGGMR_squared_norms(SEXP ThetaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type Theta(ThetaSEXP);
    rcpp_result_gen = Rcpp::wrap(squared_norms(Theta));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_CGGMR_cggm", (DL_FUNC) &_CGGMR_cggm, 15},
    {"_CGGMR_count_clusters", (DL_FUNC) &_CGGMR_count_clusters, 2},
    {"_CGGMR_find_subgraphs", (DL_FUNC) &_CGGMR_find_subgraphs, 2},
    {"_CGGMR_find_mst", (DL_FUNC) &_CGGMR_find_mst, 1},
    {"_CGGMR_median_distance", (DL_FUNC) &_CGGMR_median_distance, 1},
    {"_CGGMR_k_largest", (DL_FUNC) &_CGGMR_k_largest, 2},
    {"_CGGMR_compute_Theta", (DL_FUNC) &_CGGMR_compute_Theta, 3},
    {"_CGGMR_scaled_squared_norms", (DL_FUNC) &_CGGMR_scaled_squared_norms, 1},
    {"_CGGMR_squared_norms", (DL_FUNC) &_CGGMR_squared_norms, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_CGGMR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
