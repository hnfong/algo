// program template to be typed once and copied

#include <stdio.h>
#include <string.h>
#include <algorithm>
// #include <ext/hash_map>
#include <vector>
#include <map>
#include <set>
#include <queue>
// #include <iostream>

using namespace std;
// using namespace __gnu_cxx;

#define debug printf
#define foreach(v,c) for (typeof((c).begin()) v = (c).begin(); v != (c).end(); v++)

struct qx {
	int k, bt;
	qx (int K, int BT) { k = K; bt = BT; }
};

int main() {
	int xa,xb,ya,yb;
	int N;
	while (scanf("%d", &N) != EOF && N!= 0) {
		int n;
		map< pair<int,int>, int > m;
		map< int, pair<int,int> >mm; // debugging use
		vector<map<int,int> > adjlist;


		for (int i = 0 ; i < N ; i++) {
			scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
			pair<int,int> A = make_pair(xa, ya);
			pair<int,int> B = make_pair(xb, yb);

			if (m.count(A) == 0) {
				int tmp = m.size();
				m[A] = tmp;
				mm[tmp] = A;
				adjlist.push_back(map<int,int>());
			}
			if (m.count(B) == 0) {
				int tmp = m.size();
				m[B] = tmp;
				mm[tmp] = B;
				adjlist.push_back(map<int,int>());
			}

			int a,b;
			a = m[A];
			b = m[B];

			adjlist[a][b] = 2;
			adjlist[b][a] = 2;

		}
		n = m.size();

		int f = 0;
		for (int i = 0 ; i < n; i++) {
			// bfs
			// map< int, int > u;
			vector<qx> q;
			set<int> u;
			map<int,int> ancestry;
			unsigned int qh = 0;

			q.push_back(qx(i,-1));
			qx x(0, 0);

			while (qh != q.size()) {
				x = q[qh]; qh++;
				printf("popped %d (%d,%d)\n", x.k, mm[x.k].first, mm[x.k].second);
				foreach (it, adjlist[x.k]) {
					int v = (*it).first;
					if (u.count(v) == 0) {
						q.push_back(qx(v, qh-1));
						printf("%d %d (from %d %d)\n", mm[v].first, mm[v].second, mm[x.k].first, mm[x.k].second);
						u.insert(v);
						if (x.k == i) { ancestry[v] = v; } else { ancestry[v] = ancestry[x.k]; }
					}
				}
			}

			int z = 0;

			if (ancestry[v] == 


			printf("\n");

			if (z > f) f = z;
		}


		printf("%d\n", f);
	}
	
	return 0;
}

