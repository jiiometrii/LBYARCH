#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern double sdotfunc(double f1, double f2, long long int n, double* ASMsdot);

int main() {
	int loope = 30;
	long long int n = 1073741824;
	int i;
	LARGE_INTEGER li;
	long long int start, end;
	double PCFreq, elapse;
	QueryPerformanceFrequency(&li);
	PCFreq = (double)(li.QuadPart);
	elapse = 0.0;
	double ans;

	for (i= 0; i < loope; i++) {
		double f1 = 1.0;
		double f2 = 1.0;
		double ASMsdot = 0.0;
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ans = sdotfunc(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapse += ((double)(end - start)) * 1000.00 / PCFreq;
	}
	printf("average time for %d loop(s): %lf ms\n", loope, elapse / loope);
	if (ans != 1073741824) {
				printf("Fail\n");
	} else {
				printf("Pass\n");
	}
	/*double f1, f2, ASMsdot, ret;
	long long int n;
	n = 3;
	f1 = 1.5;
	f2 = 1.5;
	ASMsdot = 0.0;
	ret = sdotfunc(f1, f2, n, &ASMsdot);
	printf("a: %lf, b: %lf, sdot: %lf\n", f1, f2, ASMsdot);
	printf("ret = %lf\n", ret);*/
	return 0;
}