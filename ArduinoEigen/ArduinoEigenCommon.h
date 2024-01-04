#pragma once
#ifndef ARDUINO_EIGEN_COMMON_H
#define ARDUINO_EIGEN_COMMON_H

#include <ArxTypeTraits.h>

#if ARX_HAVE_LIBSTDCPLUSPLUS == 0
#error THIS PLATFORM IS NOT SUPPORTED BECAUSE THERE IS NO STANDARD LIBRARY
#else

// replace conflicting macros...
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
    return (x >= 0) ? (long)(x + 0.5) : (long)(x - 0.5);
}
#endif

#ifdef A0
namespace { constexpr size_t A0_temp {A0}; }
#undef A0
static constexpr size_t A0 {A0_temp};
#endif

#ifdef A1
namespace { constexpr size_t A1_temp {A1}; }
#undef A1
static constexpr size_t A1 {A1_temp};
#endif

#ifdef B0
namespace { constexpr size_t B0_temp {B0}; }
#undef B0
static constexpr size_t B0 {B0_temp};
#endif

#ifdef B1
namespace { constexpr size_t B1_temp {B1}; }
#undef B1
static constexpr size_t B1 {B1_temp};
#endif

#ifdef D0
namespace { constexpr size_t D0_temp {D0}; }
#undef D0
static constexpr size_t D0 {D0_temp};
#endif

#ifdef D1
namespace { constexpr size_t D1_temp {D1}; }
#undef D1
static constexpr size_t D1 {D1_temp};
#endif

#ifdef D2
namespace { constexpr size_t D2_temp {D2}; }
#undef D2
static constexpr size_t D2 {D2_temp};
#endif

#ifdef D3
namespace { constexpr size_t D3_temp {D3}; }
#undef D3
static constexpr size_t D3 {D3_temp};
#endif

#endif  // ARX_HAVE_LIBSTDCPLUSPLUS == 0

#endif  // ARDUINO_EIGEN_COMMON_H
