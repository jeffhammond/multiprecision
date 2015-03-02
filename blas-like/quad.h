#ifndef QUAD_H_DEFINED
#define QUAD_H_DEFINED

#if defined(__INTEL_COMPILER)
/* This is no longer supported in version 15 it seems.
typedef _Quad quad; */
typedef __float128 quad;
#elif defined(__GNUC__)
#include <quadmath.h>
typedef __float128 quad;
#else
#error No 128-bit float type available!
#endif

#endif // QUAD_H_DEFINED
