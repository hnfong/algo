#include <stdio.h>

/*
 @JUDGE_ID: 20044WC 474 C
 */

double d[1000002];
int e[1000002];

int main() {
	int i,k;
	d[1] = 5.0;
	e[1] = -1;
	for (i=2;i<=1000000;i++) {
		d[i] = d[i-1] / 2;
		if (d[i] < 1) {
			d[i] *= 10;
			e[i]=e[i-1]-1;
		} else {
			e[i]=e[i-1];
		};
	};
	while (scanf("%d", &k)!=EOF) {
		printf("2^-%d = %.3fe%d\n", k, d[k], e[k]);
	};
	return 0;
};

