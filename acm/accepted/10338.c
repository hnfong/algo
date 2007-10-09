#include <stdio.h>
/*
@JUDGE_ID:  20044WC 10338 C "double"
*/

double fact(int x) {
	double r;
	r = 1;
	while (x > 0) {
		r = r * x;
		x--;
	};
	return r;
};

int main() {
	long int n;
	long int i,j,k;
	char c;
	char buc[257];
	double ans;
	scanf("%d\n", &n);
	for (i=1;i<=n;++i) {
		memset(buc, 0, sizeof(buc));
		k = 0;
		ans = 0;

		while ((c = getc(stdin)) != '\n') {
			buc[c] ++ ;
			k ++;
		};
		
		ans = fact(k);

		for (j='A';j<='Z';j++) { ans = ans / fact(buc[j]); };
		
		printf("Data set %d: %0.f\n", i, ans);

	};
	return 0;
};
