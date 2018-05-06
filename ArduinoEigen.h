#ifndef ARDUINOEIGEN_H
#define ARDUINOEIGEN_H

#ifdef __AVR__
#error THIS PLATFORM IS NOT SUPPORTED
#else
#ifdef abs
#define abs_tmp abs
#undef abs
#endif
#ifdef round
#define round_tmp round
#undef round
#endif
#ifdef B1
#define B1_tmp B1
#undef B1
#endif
#endif

#include "Eigen/Eigen"

namespace Eigen
{
// https://robotics.naist.jp/edu/text/?Robotics%2FEigen#b3b26d13
template <typename t_matrix>
static t_matrix PseudoInverse(const t_matrix& m, const double &tolerance = 1.e-6)
{
    using namespace Eigen;
    typedef JacobiSVD<t_matrix> TSVD;

    unsigned int svd_opt(ComputeThinU | ComputeThinV);
    if(m.RowsAtCompileTime != Dynamic || m.ColsAtCompileTime != Dynamic)
        svd_opt= ComputeFullU | ComputeFullV;

    TSVD svd(m, svd_opt);
    const typename TSVD::SingularValuesType &sigma(svd.singularValues());
    typename TSVD::SingularValuesType sigma_inv(sigma.size());
    for(long i = 0; i < sigma.size(); ++i)
    {
        if(sigma(i) > tolerance) sigma_inv(i) = 1.0 / sigma(i);
        else                     sigma_inv(i) = 0.0;
    }
    return svd.matrixV() * sigma_inv.asDiagonal() * svd.matrixU().transpose();
}
}

#ifdef abs_tmp
#define abs abs_tmp
#endif
#ifdef round_tmp
#define round round_tmp
#endif
#ifdef B1_tmp
#define B1 B1_tmp
#endif

#endif //ARDUINOEIGEN_H
