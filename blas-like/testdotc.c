#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#ifdef _OPENMP
#include <omp.h>
#endif

#include "dotc.h"

int main(int argc, char * argv[])
{
    int n = (argc>1) ? atoi(argv[1]) : 100000;

#ifdef STACK_ALLOCATION
    quad   x128[n], y128[n], z128;
    double  x64[n],  y64[n],  z64;
    float   x32[n],  y32[n],  z32;
#else
    quad   z128;
    double  z64;
    float   z32;
    quad   * x128 = malloc(n*sizeof(quad));
    double *  x64 = malloc(n*sizeof(double));
    float  *  x32 = malloc(n*sizeof(float));
    quad   * y128 = malloc(n*sizeof(quad));
    double *  y64 = malloc(n*sizeof(double));
    float  *  y32 = malloc(n*sizeof(float));
#endif

    double t0, t1, dt32, dt64, dt128;

    for (int i=0; i<n; i++) {
        x128[i] = (quad)rand()/(quad)RAND_MAX;
        y128[i] = (quad)rand()/(quad)RAND_MAX;
    }

    for (int i=1; i<n; i++) {
        x64[i] = (double)x128[i];
        x32[i] = (float)x128[i];
        y64[i] = (double)y128[i];
        y32[i] = (float)y128[i];
    }

    dt128 = 0.0;
    dt64  = 0.0;
    dt32  = 0.0;

    for (int j=0; j<100; j++) {

        t0 = omp_get_wtime();
        mydotc128(n, x128, 1, y128, 1, &z128);
        t1 = omp_get_wtime();
        dt128 += (t1 - t0);

        t0 = omp_get_wtime();
        mydotc64(n, x64 , 1, y64 , 1, &z64);
        t1 = omp_get_wtime();
        dt64 += (t1 - t0);

        t0 = omp_get_wtime();
        mydotc32(n, x32 , 1, y32 , 1, &z32);
        t1 = omp_get_wtime();
        dt32 += + (t1 - t0);

        if (j==0) {
            /* check accuracy visually on first iteration */
            printf("128 dt=%lf, z=%40.25lf\n", dt128, (double)z128); /* Intel does not support printf of quad... */
            printf("64  dt=%lf, z=%40.25lf\n", dt64,  z64);
            printf("32  dt=%lf, z=%40.25f\n",  dt32,  z32);

            /* ignore timing for first iteration */
            dt128 = 0.0;
            dt64  = 0.0;
            dt32  = 0.0;
        }
    }
    printf("Timings %14.7lf (32b), %14.7lf (64b), %14.7lf (128b)\n", dt32, dt64, dt128);

#ifndef STACK_ALLOCATION
    free(x128);
    free( x64);
    free( x32);
    free(y128);
    free( y64);
    free( y32);
#endif

    return 0;
}
