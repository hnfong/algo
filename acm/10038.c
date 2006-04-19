#include <stdio.h>
#include <math.h>
#include <string.h>

#define false 0
#define true 1

int main() {
	int x, y, z, n;
	int i,j,k;
	int a[4000];

	while ( scanf("%d", &n) != EOF ) {
		memset(a,0,sizeof(a));
		scanf("%d", &x);
		for (i=0;i<n-1;i++) {
			scanf("%d", &y);
			z = abs(x-y);
			if (z <= 3000) { a[z]++; };
			x = y;
		};
	/*	for (i=0;i<n;i++) {
			printf("%d ", a[i]);
		};printf("\n");*/
		z = false;
		for (i=1;i<n;i++) {
			if (a[i] != 1) { printf("Not jolly\n"); z = true; break; };
		};
		if (z ==false ){ printf("Jolly\n");};
		};
	return 0;
};

