#include "quad.h"

/* z = x[] . y[] */
void mydotc32(int n, float x[n], int jx, float y[n], int jy, float * z);
void mydotc64(int n, double x[n], int jx, double y[n], int jy, double * z);
void mydotc128(int n, quad x[n], int jx, quad y[n], int jy, quad * z);

/* y[] = a * x[] */
void myscalc32(int n, float a, float x[n], int jx, float y[n], int jy);
void myscalc64(int n, double a, double x[n], int jx, double y[n], int jy);
void myscalc128(int n, quad a, quad x[n], int jx, quad y[n], int jy);

/* y[] = x[] */
void mycopyc32(int n, float x[n], int jx, float y[n], int jy);
void mycopyc64(int n, double x[n], int jx, double y[n], int jy);
void mycopyc128(int n, quad x[n], int jx, quad y[n], int jy);

/* y[] = pow(x[],a) - not using pow()  */
void mypowc32(int n, int a, float x[n], int jx, float y[n], int jy);
void mypowc64(int n, int a, double x[n], int jx, double y[n], int jy);
void mypowc128(int n, int a, quad x[n], int jx, quad y[n], int jy);
