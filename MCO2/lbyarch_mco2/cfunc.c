#include <stdio.h>

double sdotInC(double f1, double f2, long long n, double* ASMsdot) {
    double sum = 0.0;
    for (long long i = 0; i < n; i++) {
        sum += f1 * f2;
    }
    *ASMsdot = sum;
    return sum;
}