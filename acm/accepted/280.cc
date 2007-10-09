#include <stdio.h>
#include <string.h>

int n;
bool w[100][100];
bool u[100];

void flood(int k, bool flag) {
	if (u[k]) return;
	if (flag) u[k] = true;
	for (int i = 0 ; i < n; i++) {
		if (w[k][i]) { flood(i, true); }
	}
}

int main() {
	while (true) {
		memset(w,0,sizeof(w));
		scanf("%d", &n);
		if (n == 0) break;

		int a,b;
		while (true) {
			scanf("%d", &a);
			if (a == 0) break;

			while (true) {
				scanf("%d", &b);
				if (b == 0) break;

				w[a-1][b-1] = 1;
			}
		}

		// initial vertices

		int k;
		scanf("%d", &k);
		for (int i = 0 ; i < k; i++) {
			int t;
			scanf("%d", &t);
			t--;
			memset(u,0,sizeof(u));
			flood(t, false);

			int z = 0;
			for (int j = 0 ; j < n; j++) {
				if (u[j] == false) z ++;
			}
			printf("%d", z);
			for (int j = 0 ; j < n; j++) {
				if (u[j] == false) printf(" %d", j+1);
			}
			printf("\n");
		}
	}
}
