#include "quad.h"

void mydotc32(int n, float x[n], int jx, float y[n], int jy, float * z)
{
    float r = 0.0;
    for (int i=0; i<n; i++) {
        r += x[i] * y[i];
    }
    *z = r;
    return;
}

void mydotc64(int n, double x[n], int jx, double y[n], int jy, double * z)
{
    double r = 0.0;
    for (int i=0; i<n; i++) {
        r += x[i] * y[i];
    }
    *z = r;
    return;
}

void mydotc128(int n, quad x[n], int jx, quad y[n], int jy, quad * z)
{
    quad r = 0.0;
    for (int i=0; i<n; i++) {
        r += x[i] * y[i];
    }
    *z = r;
    return;
}
