#ifndef ARDUINOEIGEN_H
#define ARDUINOEIGEN_H

#include <Arduino.h>
#include <ArxTypeTraits.h>

#if ARX_HAVE_LIBSTDCPLUSPLUS == 0
#error THIS PLATFORM IS NOT SUPPORTED BECAUSE THERE IS NO STANDARD LIBRARY
#else

//
#ifdef abs
#undef abs
template <typename T>
static constexpr T abs(const T& x) {
    return (x > 0) ? x : -x;
}
#endif
#ifdef round
#undef round
template <typename T>
static constexpr T round(const T& x) {
    return (x >= 0) ? (long)(x +0.5) : (long)(x - 0.5);
}
#endif
#ifdef B1
#undef B1
static constexpr size_t B1 {1};
#endif
#ifdef F
#undef F
static constexpr const __FlashStringHelper* F(const char* str) {
    return reinterpret_cast<const __FlashStringHelper*>(PSTR(str));
}
#endif
#endif  // ARX_HAVE_LIBSTDCPLUSPLUS == 0

// guarantee that the Eigen code that you are #including is licensed under the MPL2
#define EIGEN_MPL2_ONLY
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

#endif //ARDUINOEIGEN_H
