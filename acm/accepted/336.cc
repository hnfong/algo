#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

int w[30][30];
int u[30];
int n;

int qt, qh;
int ql[1000];
int qk[1000];

map<int,int> m;

int main() {
	int k;
	while (scanf("%d", &k), k) {
		m.clear();
		memset(w,0,sizeof(w));
		qt = qh = 0;

		n = 0;

		for (int i = 0 ; i < k; i++) {
			int a,b;
			scanf("%d %d", &a, &b);

			if (m.count(a) == 0) m[a] = n++;
			if (m.count(b) == 0) m[b] = n++;

			int x = m[a];
			int y = m[b];
			w[x][y] = 1;
			w[y][x] = 1;
		}

		int start, ttl;

		while (scanf("%d %d", &start, &ttl), start) {
			// flood
			
			qk[qt] = m[start];
			ql[qt] = ttl;
			qt++;
			memset(u,0,sizeof(u));
			u[m[start]] = 1;

			while (qh != qt) {
				int k = qk[qh];
				int l = ql[qh];
				qh++;

				if (l == 0) continue;
				
				for (int i = 0 ; i < n ; i++) {
					if (!u[i] && w[k][i]) {
						qk[qt] = i;
						ql[qt] = l-1;
						qt++;
						u[i] = 1;
					}
				}
			}

			int z = 0;
			for (int i = 0 ; i < n; i++) {
				if (!u[i]) z ++;
			}
			static int cse = 1;

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cse++, z, start, ttl);
		}
	}
}
