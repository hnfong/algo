#include <stdio.h>
#include <string.h>

/*
 @JUDGE_ID: 20044WC 369 C
 */
int mypow(int x,int y) {
	int z = 1;
	for (;y>0;y--) { z*=x; };
	return z;
};

int main() {
	int i,j,k,n,m;
	int w[25];
	int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int pp[101][25];
	/* preprocess */
	memset(pp,0,sizeof(pp));
	for (i=2;i<=100;i++) {
		k = i;
		for (j=0;j<25;j++){
			while (k%p[j]==0) {
				pp[i][j]++;
				k /= p[j];
			};
		};
	};
	for (i=2;i<=100;i++) {
		for (j=0;j<25;j++) {
			pp[i][j] = pp[i][j]+pp[i-1][j];
		};
	};

	/* start reading */
	
	while (1) {
		scanf("%d %d", &n, &m);
		if (n==0&&m==0) {
			return 0;
		};
		k = n-m;
		for (j=0;j<25;j++) {
			w[j]=pp[n][j]-pp[m][j]-pp[k][j];
		}; 
		k = 1;
		for (i=0;i<25;i++) {
			k *= mypow(p[i],w[i]);
		};
		printf("%d things taken %d at a time is %d exactly.\n", n,m,k);
	};
};

