#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern double sdotfunc(double f1, double f2, long long int n, double* ASMsdot);
extern double sdotInC(double f1, double f2, long long n, double* ASMsdot);

int main() {
	int asm_pass = 0;
	int c_pass = 0;
	double c_time30[30];
	double asm_time30[30];
	double c_time24[30];
	double asm_time24[30];
	double c_time20[30];
	double asm_time20[30];
	int loope = 30;
	long long int n;
	int i;
	LARGE_INTEGER li;
	long long int start, end;
	double PCFreq, elapseC = 0.0, elapseAsm = 0.0;
	double ansC, ansAsm;
	double totalElapseC = 0.0;
	double totalElapseAsm = 0.0;
	QueryPerformanceFrequency(&li);
	PCFreq = (double)(li.QuadPart);

	for (i = 0; i < loope; i++) {
		n = 1073741824;
		double f1 = 1.0;
		double f2 = 1.0;
		double ASMsdot = 0.0;
		elapseC = 0.0;
		elapseAsm = 0.0;

		// time for C function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansC = sdotInC(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		c_time30[i] = ((double)(end - start)) * 1000.00 / PCFreq;
		elapseC += ((double)(end - start)) * 1000.00 / PCFreq;
		totalElapseC += elapseC;

		/*if (ansC == 1073741824)
			printf("C function 2^30 Pass %d\n", i + 1);
		else
			printf("C function 2^30 Fail %d\n", i + 1);*/
		if (ansC == 1073741824)
			c_pass++;

		// time for asm function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansAsm = sdotfunc(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		asm_time30[i] = ((double)(end - start)) * 1000.00 / PCFreq;
		elapseAsm += ((double)(end - start)) * 1000.00 / PCFreq;
		totalElapseAsm += elapseAsm;

		//if (ansAsm == 1073741824)
			//printf("ASM function 2^30 Pass %d\n", i + 1);
		if (ansAsm == 1073741824)
			asm_pass++;

		//printf("\n");
	}


	printf("----------\n");
	//UNCOMMENT TO SEE THE TIME FOR EACH LOOP
	/*printf("C function in 2^30 time: [");
	for (int i = 0; i < 30; i++) {
		printf("%.4lf ", c_time30[i]);
	}
	printf("]\n");
	printf("ASM function in 2^30 time: [");
	for (int i = 0; i < 30; i++) {
		printf("%.4lf ", asm_time30[i]);
	}
	printf("]\n\n"); */
	printf("C function in 2^30 finished with average time: %lf ms\n", elapseC / loope);
	printf("C function in 2^30 finished with %d%% CORRECTNESS\n", (c_pass / 30)*100);
	printf("ASM function in 2^30 finished with average time: %lf ms\n", elapseAsm / loope);
	printf("ASM function in 2^30 finished with %d%% CORRECTNESS\n", (asm_pass / 30)*100);
	printf("----------\n\n");

	c_pass = 0;
	asm_pass = 0;
	for (i = 0; i < loope; i++) {
		n = 16777216;
		double f1 = 1.0;
		double f2 = 1.0;
		double ASMsdot = 0.0;
		elapseC = 0.0;
		elapseAsm = 0.0;

		// time for C function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansC = sdotInC(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		c_time24[i] = ((double)(end - start)) * 1000.00 / PCFreq;
		elapseC += ((double)(end - start)) * 1000.00 / PCFreq;
		totalElapseC += elapseC;

		/*if (ansC == 16777216)
			printf("C function 2^24 Pass %d\n", i + 1);
		else
			printf("C function 2^24 Fail %d\n", i + 1);*/
		if (ansC == 16777216)
			c_pass++;

		// time for asm function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansAsm = sdotfunc(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		asm_time24[i] = ((double)(end - start)) * 1000.00 / PCFreq;
		elapseAsm += ((double)(end - start)) * 1000.00 / PCFreq;
		totalElapseAsm += elapseAsm;

		//if (ansAsm == 16777216)
		//	printf("ASM function 2^24 Pass %d\n", i + 1);
		//else
		//	printf("ASM function 2^24 Fail %d\n", i + 1);
		if (ansAsm == 16777216)
			asm_pass++;

		//printf("\n");
	}

	printf("----------\n");
	//UNCOMMENT TO SEE THE TIME FOR EACH LOOP
	/*printf("C function in 2^24 time: [");
	for (int i = 0; i < 30; i++) {
		printf("%.4lf ", c_time24[i]);
	}
	printf("]\n");
	printf("ASM function in 2^24 time: [");
	for (int i = 0; i < 30; i++) {
		printf("%.4lf ", asm_time24[i]);
	}
	printf("]\n\n");*/
	printf("C function in 2^24 finished with average time: %lf ms\n", elapseC / loope);
	printf("C function in 2^24 finished with %d%% CORRECTNESS\n", (c_pass / 30) * 100);
	printf("ASM function in 2^24 finished with average time: %lf ms\n", elapseAsm / loope);
	printf("ASM function in 2^24 finished with %d%% CORRECTNESS\n", (asm_pass / 30) * 100);
	printf("----------\n\n");

	asm_pass = 0;
	c_pass = 0;
	for (i = 0; i < loope; i++) {
		n = 1048576;
		double f1 = 1.0;
		double f2 = 1.0;
		double ASMsdot = 0.0;
		elapseC = 0.0;
		elapseAsm = 0.0;

		// time for C function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansC = sdotInC(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		c_time20[i] = ((double)(end - start)) * 1000.00 / PCFreq;
		elapseC += ((double)(end - start)) * 1000.00 / PCFreq;
		totalElapseC += elapseC;

		//if (ansC == 1048576)
		//	printf("C function 2^20 Pass %d\n", i+1);
		//else
		//	printf("C function 2^20 Fail %d\n", i+1);
		if (ansC == 1048576)
			c_pass++;

		// time for asm function
		QueryPerformanceCounter(&li);
		start = li.QuadPart;
		ansAsm = sdotfunc(f1, f2, n, &ASMsdot);
		QueryPerformanceCounter(&li);
		end = li.QuadPart;
		asm_time20[i] = ((double)(end - start)) * 1000.00 / PCFreq;
		elapseAsm += ((double)(end - start)) * 1000.00 / PCFreq;
		totalElapseAsm += elapseAsm;

		//if (ansAsm == 1048576)
		//	printf("ASM function 2^20 Pass %d\n", i+1);
		//else
		//	printf("ASM function 2^20 Fail %d\n", i+1);
		if (ansAsm == 1048576)
			asm_pass++;

		//printf("\n");
	}

	printf("----------\n");
	//UNCOMMENT TO SEE THE TIME FOR EACH LOOP
	/*printf("C function in 2^20 time: [");
	for (int i = 0; i < 30; i++) {
		printf("%.4lf ", c_time20[i]);
	}
	printf("]\n");
	printf("ASM function in 2^20 time: [");
	for (int i = 0; i < 30; i++) {
		printf("%.4lf ", asm_time20[i]);
	}
	printf("]\n\n");*/
	printf("C function in 2^20 finished with average time: %lf ms\n", elapseC / loope);
	printf("C function in 2^20 finished with %d%% CORRECTNESS\n", (c_pass / 30) * 100);
	printf("ASM function in 2^20 finished with average time: %lf ms\n", elapseAsm / loope);
	printf("ASM function in 2^20 finished with %d%% CORRECTNESS\n", (asm_pass / 30) * 100);
	printf("----------\n\n");

	printf("----------------------------------------\n");
	printf("Total Average:\n");
	printf("Average time for C function over all loop(s): %lf ms\n", totalElapseC / loope);
	printf("Average time for x86-64 function over all loop(s): %lf ms\n", totalElapseAsm / loope);
	printf("----------------------------------------\n\n");

	return 0;
}