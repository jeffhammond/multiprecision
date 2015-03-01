#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main(int argc, char* argv[])
{
    float f32a = 10000.0, f32b = 0.00001;
    printf("pi = %f e = %f\n", f32a, f32b);

    int64_t i64a = (double)f32a / (double)FLT_EPSILON;
    int64_t i64b = (double)f32b / (double)FLT_EPSILON;

    int64_t i64c = i64a + i64b;

    float f32c = i64c * FLT_EPSILON;
    printf("sum = %f (should be %f)\n", f32c, f32a+f32b);

    printf("x=%x\n",1.0f);

    return 0;
}
