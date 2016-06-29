#include <stdio.h>
#include <math.h>

int main() {
	int n;
	int a[100][2];
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		long long f = 0;
		for (int i = 0 ; i < n ; i++ ) {
			scanf("%d %d", &a[i][0], &a[i][1]);
			for (int j = i-1; j >= 0; j-- ){ 
				long long dx = a[i][0]-a[j][0];
				long long dy = a[i][1]-a[j][1];
				long long int t = dx*dx + dy*dy;
				if (t > f) f = t;
			};
		};
		long double r;
		scanf("%Lf", &r);
		if (r < 0) while (1);
		long double d = r * 2;
		printf("%Ld %Lf %Lf\n", f, (long double) sqrt(f) , d);
		if (d*d >= f) {
			printf("The polygon can be packed in the circle.\n");
		} else {
			printf("There is no way of packing that polygon.\n");
		};
	};
};

