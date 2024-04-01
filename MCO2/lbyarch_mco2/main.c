#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern double sdotfunc(double f1, double f2, long long int n, double* ASMsdot);
extern double sdotInC(double f1, double f2, long long n, double* ASMsdot);

int main() {
	int loope = 30;
	long long int n;
	int i;
	LARGE_INTEGER li;
	long long int start, end;
	double PCFreq, elapseC = 0.0, elapseAsm = 0.0;
	double ansC, ansAsm;
	QueryPerformanceFrequency(&li);
	PCFreq = (double)(li.QuadPart);

	for (i = 0; i < loope; i++) {
		n = 1073741824;
		double f1 = 1.0;
		double f2 = 1.0;
		double ASMsdot = 0.0;

		// time for C function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansC = sdotInC(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapseC += ((double)(end - start)) * 1000.00 / PCFreq;

		if (ansC == 1073741824)
			printf("C function 2^30 Pass %d\n", i + 1);
		else
			printf("C function 2^30 Fail %d\n", i + 1);

		// time for asm function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansAsm = sdotfunc(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapseAsm += ((double)(end - start)) * 1000.00 / PCFreq;

		if (ansAsm == 1073741824)
			printf("ASM function 2^30 Pass %d\n", i + 1);
		else
			printf("ASM function 2^30 Fail %d\n", i + 1);

		printf("\n");
	}

	printf("\n");

	for (i = 0; i < loope; i++) {
		n = 16777216;
		double f1 = 1.0;
		double f2 = 1.0;
		double ASMsdot = 0.0;

		// time for C function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansC = sdotInC(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapseC += ((double)(end - start)) * 1000.00 / PCFreq;

		if (ansC == 16777216)
			printf("C function 2^24 Pass %d\n", i + 1);
		else
			printf("C function 2^24 Fail %d\n", i + 1);

		// time for asm function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansAsm = sdotfunc(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapseAsm += ((double)(end - start)) * 1000.00 / PCFreq;

		if (ansAsm == 16777216)
			printf("ASM function 2^24 Pass %d\n", i + 1);
		else
			printf("ASM function 2^24 Fail %d\n", i + 1);

		printf("\n");
	}

	printf("\n");

	for (i = 0; i < loope; i++) {
		n = 1048576;
		double f1 = 1.0;
		double f2 = 1.0;
		double ASMsdot = 0.0;

		// time for C function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansC = sdotInC(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapseC += ((double)(end - start)) * 1000.00 / PCFreq;

		if (ansC == 1048576)
			printf("C function 2^20 Pass %d\n", i+1);
		else
			printf("C function 2^20 Fail %d\n", i+1);

		// time for asm function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansAsm = sdotfunc(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		elapseAsm += ((double)(end - start)) * 1000.00 / PCFreq;

		if (ansAsm == 1048576)
			printf("ASM function 2^20 Pass %d\n", i+1);
		else
			printf("ASM function 2^20 Fail %d\n", i+1);

		printf("\n");
	}

	printf("----------------------------------------\n");
	printf("ANALYSIS:\n");
	printf("Average time for C function over all loop(s): %lf ms\n", elapseC / loope);
	printf("Average time for x86-64 function over all loop(s): %lf ms\n", elapseAsm / loope);

	return 0;
}