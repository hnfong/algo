#include <stdio.h>
#include <string.h>

int main() {
	int cse;
	int w[100];

	scanf("%d", &cse);
	while (cse--) {
		int n,m;
		scanf("%d %d", &n, &m) ;
		memset(w,0,sizeof(w));

		for (int i = 0 ; i < m ; i++) {
			for (int j = 0 ; j < n; j++) {
				int k; scanf("%d", &k);
				if (k == 1) { w[j]++; }
			}
		}

		long long ans = 1;
		for (int i = 0 ; i < n; i++) {
			ans *= w[i] ? w[i] : 1;
		}
		printf("%lld\n", ans);
	}
}
