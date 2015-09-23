#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

typedef union {
  struct {
    unsigned int     mantissa : 23;
    unsigned int     exponent : 8;
    unsigned char    sign : 1;
  } internal;
  float number;
} sp_t;

int main(int argc, char* argv[])
{
    int32_t i1 = -4194303;
    int32_t i2 = -8388607;
    int32_t i3 = -4194302;
    int32_t i4 = -8388606;

    sp_t x,y;

    memcpy(&x,&i2,4);
    y.number = x.number+0.0f;
    printf("x.number=%f\n", x.number);
    printf("y.number=%f\n", y.number);
    printf("x.internal=%d,%d,%c\n", x.internal.mantissa, x.internal.exponent, x.internal.sign);
    printf("y.internal=%d,%d,%c\n", y.internal.mantissa, y.internal.exponent, y.internal.sign);

    return 0;
}
