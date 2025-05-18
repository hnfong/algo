#include <stdio.h>
#include <math.h>

#define true 1
#define false 0

int dat[10001];

int isprime(int n) {
	int i;
	int s = (int) sqrt(n);
	for (i = 2; i <= s; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	int i;
	int a, b;
	int z;

	for (i = 0; i <= 10000;i ++)  {
		dat[i] = isprime(i*i+i+41);
	}

	while (!feof(stdin)) {
		scanf("%d %d", &a, &b);
		z = 0;
		for (i = a; i <= b; i++) {
			z += dat[i];
		}
		printf("%.2f\n", z * 100.0 / (1.0* (b+1-a)));
	}
	return 0;
}
