#include <stdio.h>
#include <stdlib.h>

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

void myscalc32(int n, float a, float x[n], int jx, float y[n], int jy)
{
    for (int i=0; i<n; i++) {
        y[i] = a * x[i];
    }
    return;
}

void myscalc64(int n, double a, double x[n], int jx, double y[n], int jy)
{
    for (int i=0; i<n; i++) {
        y[i] = a * x[i];
    }
    return;
}

void myscalc128(int n, quad a, quad x[n], int jx, quad y[n], int jy)
{
    for (int i=0; i<n; i++) {
        y[i] = a * x[i];
    }
    return;
}

void mycopyc32(int n, float x[n], int jx, float y[n], int jy)
{
    for (int i=0; i<n; i++) {
        y[i] = x[i];
    }
    return;
}

void mycopyc64(int n, double x[n], int jx, double y[n], int jy)
{
    for (int i=0; i<n; i++) {
        y[i] = x[i];
    }
    return;
}

void mycopyc128(int n, quad x[n], int jx, quad y[n], int jy)
{
    for (int i=0; i<n; i++) {
        y[i] = x[i];
    }
    return;
}

void mypowc32(int n, int a, float x[n], int jx, float y[n], int jy)
{
    switch (a) {
        case 1:
            for (int i=0; i<n; i++) {
                y[i] = x[i];
            }
            break;
        case 2:
            for (int i=0; i<n; i++) {
                y[i] = x[i] * x[i];
            }
            break;
        case 3:
            for (int i=0; i<n; i++) {
                y[i] = x[i] * x[i] * x[i];
            }
            break;
        case 4:
            for (int i=0; i<n; i++) {
                float t = x[i] * x[i];
                y[i] = t * t;
            }
            break;
        case 5:
            for (int i=0; i<n; i++) {
                float t = x[i] * x[i];
                y[i] = t * t * x[i];
            }
            break;
        case 6:
            for (int i=0; i<n; i++) {
                float t = x[i] * x[i];
                y[i] = t * t * t;
            }
            break;
        default:
            printf("exponent of %d not supported\n", a);
            abort();
            break;
    }
    return;
}

void mypowc64(int n, int a, double x[n], int jx, double y[n], int jy)
{
    switch (a) {
        case 1:
            for (int i=0; i<n; i++) {
                y[i] = x[i];
            }
            break;
        case 2:
            for (int i=0; i<n; i++) {
                y[i] = x[i] * x[i];
            }
            break;
        case 3:
            for (int i=0; i<n; i++) {
                y[i] = x[i] * x[i] * x[i];
            }
            break;
        case 4:
            for (int i=0; i<n; i++) {
                double t = x[i] * x[i];
                y[i] = t * t;
            }
            break;
        case 5:
            for (int i=0; i<n; i++) {
                double t = x[i] * x[i];
                y[i] = t * t * x[i];
            }
            break;
        case 6:
            for (int i=0; i<n; i++) {
                double t = x[i] * x[i];
                y[i] = t * t * t;
            }
            break;
        default:
            printf("exponent of %d not supported\n", a);
            abort();
            break;
    }
}

void mypowc128(int n, int a, quad x[n], int jx, quad y[n], int jy)
{
    switch (a) {
        case 1:
            for (int i=0; i<n; i++) {
                y[i] = x[i];
            }
            break;
        case 2:
            for (int i=0; i<n; i++) {
                y[i] = x[i] * x[i];
            }
            break;
        case 3:
            for (int i=0; i<n; i++) {
                y[i] = x[i] * x[i] * x[i];
            }
            break;
        case 4:
            for (int i=0; i<n; i++) {
                quad t = x[i] * x[i];
                y[i] = t * t;
            }
            break;
        case 5:
            for (int i=0; i<n; i++) {
                quad t = x[i] * x[i];
                y[i] = t * t * x[i];
            }
            break;
        case 6:
            for (int i=0; i<n; i++) {
                quad t = x[i] * x[i];
                y[i] = t * t * t;
            }
            break;
        default:
            printf("exponent of %d not supported\n", a);
            abort();
            break;
    }
    return;
}

