#include <stdio.h>
#include <string.h>
#include <algorithm>

#define INFINITY 1000000000

int main() {
	int n,m;
	int a[1000];

	int dp[600][600][2];
	int bt[600][600][2];
	memset(bt,0,sizeof(bt));
	memset(dp,0,sizeof(dp));
	
	scanf("%d %d\n", &n, &m);
	for (int i = 0 ; i < n ; i ++ ) {
		scanf("%d", &a[i]);
	};

	std::sort(a,a+n);

	for (int j = 1 ; j <= m ; j++ ) {
		dp[0][j][0] = INFINITY;
		dp[0][j][1] = INFINITY;
		for (int i = 1 ; i < n ; i ++ ) {
			dp[i][j][0] = dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][1];
			
			int k = dp[i-1][j-1][0]+(a[i]-a[i-1])*(a[i]-a[i-1]);
			if (k < dp[i][j][1]) {
				dp[i][j][1] = k;
				bt[i][j][1] = 1;
			};
		};
	};

	/*for (int i = 0 ; i < n ; i++ ) {
		printf("[%.2d]", a[i]);
	};printf("\n");
	
	for (int i = 0 ; i <= m ; i ++  ) {
		for (int j = 0 ; j < n ; j++ ) {
			printf("[%.2d]", dp[j][i][1] == INFINITY ? 99 : dp[j][i][1]);
		}; 
		printf("\n");
	};
	for (int i = 0 ; i <= m ; i ++  ) {
		for (int j = 0 ; j < n ; j++ ) {
			printf("[%.2d]", bt[j][i][1]);
		}; 
		printf("\n");
	};

	printf("\n");

	for (int i = 0 ; i < n ; i++ ) {
		printf("[%.2d]", a[i]);
	};printf("\n");
	
	for (int i = 0 ; i <= m ; i ++  ) {
		for (int j = 0 ; j < n ; j++ ) {
			printf("[%.2d]", dp[j][i][0] == INFINITY ? 99 : dp[j][i][0]);
		}; 
		printf("\n");
	};
	for (int i = 0 ; i <= m ; i ++  ) {
		for (int j = 0 ; j < n ; j++ ) {
			printf("[%.2d]", bt[j][i][0]);
		}; 
		printf("\n");
	};
	*/

	printf("%d\n", dp[n-1][m][1]);
	
	int nk = n-1;
	int mk = m;

	do {
		if (bt[nk][mk][1] == 1) {
			mk--;
			printf("%d %d\n", a[nk-1], a[nk]);
			nk--;
		};
		nk --;
	} while (mk > 0);
};

