#ifndef QUAD_H_DEFINED
#define QUAD_H_DEFINED

#if defined(__INTEL_COMPILER)
/* This requires 
 * CFLAGS+=-Qoption,cpp,--extended_float_type
typedef _Quad quad; */
typedef __float128 quad;
/* This does not work...
 * #include <stddef.h>
 * int quadmath_snprintf (char *s, size_t size, const char *format, ...); */
/* This does not work...
 * #include <quadmath.h> */
#elif defined(__GNUC__)
#include <quadmath.h>
typedef __float128 quad;
#else
#error No 128-bit float type available!
#endif

#endif // QUAD_H_DEFINED
