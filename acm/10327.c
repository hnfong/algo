#include <stdio.h>

int main () {
	long int i,j,k,n;
	long int c;
	long int a[2000];
	while (scanf("%d", &n) != EOF) {
		c = 0;
		for (i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		};
		for (i=1;i<=n-1;i++) {
			for (j=i;j>=1;j--) {
				if (a[j] > a[j+1]) {
					k = a[j];
					a[j] = a[j+1];
					a[j+1] = k;
					c++;
				};
			};
		};
		printf("Minimum exchange operations : %d\n", c);
	};
	return 0;
};
