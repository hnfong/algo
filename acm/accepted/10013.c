#include <stdio.h>
/*
 @JUDGE_ID: 20044WC 10013 C
 */

int main() {
	int i,t,n,k;
	short int w[1000000];
	scanf("%d",&t);
	for (;t>0;t--) {
		scanf("%d", &n);
		for (i=0;i<n;i++) {
			scanf("%d %d", &w[i], &k);
			w[i] += k;
		};
		for (i=n-2;i>=0;i--) {
			w[i]+= (w[i+1]/10);
			w[i+1] = w[i+1] % 10;
		};
		for (i=0;i<n;i++) {
			printf("%d", w[i]);
		};
		printf("\n");
		if (t>1) printf("\n");
	};
	return 0;
};
