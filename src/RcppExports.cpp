// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// updateInverse
Eigen::MatrixXd updateInverse(const Eigen::MatrixXd& inverse, const Eigen::VectorXd& vec, int i);
RcppExport SEXP _CGGMR_updateInverse(SEXP inverseSEXP, SEXP vecSEXP, SEXP iSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const Eigen::MatrixXd& >::type inverse(inverseSEXP);
    Rcpp::traits::input_parameter< const Eigen::VectorXd& >::type vec(vecSEXP);
    Rcpp::traits::input_parameter< int >::type i(iSEXP);
    rcpp_result_gen = Rcpp::wrap(updateInverse(inverse, vec, i));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_CGGMR_updateInverse", (DL_FUNC) &_CGGMR_updateInverse, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_CGGMR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
