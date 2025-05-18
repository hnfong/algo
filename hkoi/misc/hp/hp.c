#define length 100 //maximum length of the high precision arithmetic operations (the larger the number, the slower operations will be, especially for multiplication) also a higher number will be required for factorials...

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "common.h"
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "fact.h"

int main() {
	printf("Addition :\n");
	hpadd();
	printf("Subtraction :\n");
	hpsub();
	printf("Multiplication :\n");
	hpmul();
	printf("Factorial :\n");
	hpfact();
	return 0;
};
