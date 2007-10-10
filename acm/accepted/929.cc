#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct nod {
	int r,c,v;
	nod (int rr, int cc,int vv) { r = rr; c = cc; v = vv; }
	bool operator<(const nod &t) const { return v > t.v; }
};

int dr[] = {0,0,-1,1};
int dc[] = {-1,1,0,0};

int main() {
	int cse;
	scanf("%d", &cse);

	while (cse --) {
		priority_queue<nod> q;
		int n,m;
		scanf("%d", &n);
		scanf("%d", &m);
		int w[n][m];
		int v[n][m];

		for (int i = 0 ; i < n; i++) {
			for (int j = 0 ; j < m; j++) {
				scanf("%d", &w[i][j]);
				v[i][j] = 1000000000;
			}
		}

		q.push(nod(0,0,w[0][0]));
		v[0][0] = w[0][0];

		while (!q.empty()) {
			nod t = q.top();
			q.pop();
			if (t.r == n - 1 && t.c == m - 1) break;

			for (int i = 0 ; i < 4 ; i ++) {
				int rr = t.r + dr[i];
				int cc = t.c + dc[i];
				int vv = t.v + w[rr][cc];

				if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
				if (v[rr][cc] <= vv) continue;

				q.push(nod(rr,cc,vv));
				v[rr][cc] = vv;
			}
		}

		printf("%d\n", v[n-1][m-1]);
	}
}
