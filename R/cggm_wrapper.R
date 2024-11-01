# Wrapper function for the C++ function .cggm(). Its main purpose is to convert
# inputs to the appropriate formats and convert the output into an easily
# accessible list.
.cggm_wrapper <- function(S, W, lambda, gss_tol, conv_tol, fusion_threshold,
                          tau, max_iter, store_all_res, verbose)
{
    # Initial estimate for Theta
    Theta = CGGMR:::.initial_Theta(S)

    # Extract R and A from Theta
    R = Theta
    diag(R) = 0
    A = diag(Theta)

    # Each observation starts as its own cluster
    u = c(1:ncol(S)) - 1

    # All cluster sizes are 1
    p = rep(1, ncol(S))

    if (is.null(fusion_threshold)) {
        # Get the median distance between two rows/columns in Theta
        m = CGGMR:::.median_distance(Theta)

        # Set the fusion_threshold to a small value relative to the median
        # distance as threshold for fusions, if the median is too small,
        # i.e., when Theta is mostly clustered into a single cluster, a
        # buffer is added
        fusion_threshold = tau * max(m, 1e-8)
    }

    # Weight matrix
    W_sparse = CGGMR:::.convert_to_sparse(W)

    # Scaling factor for the penalty
    scale_factor = nrow(S) / sum(W[lower.tri(W)]) / sqrt(nrow(S) - 1)

    # Execute algorithm
    result = CGGMR:::.cggm(
        W_keys = W_sparse$keys, W_values = W_sparse$values, Ri = R, Ai = A,
        pi = p, ui = u, S = S, lambdas = lambda, eps_fusions = fusion_threshold,
        scale_factor = scale_factor, gss_tol = gss_tol, conv_tol = conv_tol,
        max_iter = max_iter, store_all_res = store_all_res, verbose = verbose
    )

    # Convert output
    losses = result$losses
    lambdas_res = result$lambdas
    cluster_counts = result$cluster_counts
    result = CGGMR:::.convert_cggm_output(result)
    result$losses = losses
    result$lambdas = lambdas_res
    result$cluster_counts = cluster_counts

    # Add the fusion threshold to the result
    result$fusion_threshold = fusion_threshold

    # Create a vector where the nth element contains the index of the solution
    # where n clusters are found for the first time. If an element is -1, that
    # number of clusters is not found
    cluster_solution_index = rep(-1, nrow(S))
    for (i in 1:length(result$cluster_counts)) {
        c = result$cluster_counts[i]

        if (cluster_solution_index[c] < 0) {
            cluster_solution_index[c] = i
        }
    }
    result$cluster_solution_index = cluster_solution_index

    # The number of solutions
    result$n = length(cluster_counts)

    # Also add other input values, these are useful for other functions
    result$inputs = list()
    result$inputs$S = S
    result$inputs$W = W
    result$inputs$gss_tol = gss_tol
    result$inputs$conv_tol = conv_tol
    result$inputs$max_iter = max_iter

    return(result)
}
