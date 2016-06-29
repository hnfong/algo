#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int main() {
	int i,j,k;
	int m,n;
	map<int,int> moliu;
	int a[1000];
	int v[1000];
	int dp[20000];
	int bt[20000];
	memset(a,0,sizeof(a));
	memset(v,0,sizeof(v));
	memset(dp,0,sizeof(dp));
	memset(bt,0,sizeof(bt));
	
	scanf("%d %d\n", &m, &n);

	for (int i=0;i<n;i++) {
		scanf("%d", &v[i]);
		moliu[v[i]] = i;
	};

	dp[0] = 0;
	bt[0] = -1;

	for (int i = 1;i<=m;i++) {
		dp[i] = 99999;
		for (int j = 0; j < n; j++) {
			if (i-v[j]<0) continue;
			if (dp[i-v[j]] < dp[i]) { 
				dp[i] = dp[i-v[j]]+1;
				bt[i] = i-v[j];
			};
		};
	};

	k = m;
	int total = 0;

	while (bt[k] != -1) {
		a[moliu[k-bt[k]]]++;
		k = bt[k];
		total++;
	};

	printf("%d\n", total);
	for (int i=0; i < n;i++) {
		printf("%d\n", a[i]);
	};
};

