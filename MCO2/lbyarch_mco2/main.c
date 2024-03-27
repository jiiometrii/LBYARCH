#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
extern double sdotfunc(double f1, double f2, long long int n, double* ASMsdot);

int main() {
	double f1, f2, ASMsdot, ret;
	long long int n;
	n = 3;
	f1 = 1.5;
	f2 = 1.5;
	ASMsdot = 0.0;
	ret = sdotfunc(f1, f2, n, &ASMsdot);
	printf("a: %lf, b: %lf, sdot: %lf\n", f1, f2, ASMsdot);
	printf("ret = %lf\n", ret);
	return 0;
}