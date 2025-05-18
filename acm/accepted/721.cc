#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct nod {
	int k,v;
	nod (int kk, int vv) {
		this->k = kk;
		this->v = vv;
	}

	bool operator<(const nod &b) const { return this->v > b.v; }
};

#define BIG 2000000000

int main() {
	int cse;
	scanf("%d", &cse);

	while (cse--) {
		int n, Q;

		scanf("%d %d", &n, &Q);
		int v[n];
		vector<pair<int,int> > w[n];
		vector<pair<int,int> > u[n];

		for (int i = 0 ; i < Q; i++) {
			int a,b,c;
			scanf("%d %d %d", &a,&b,&c);
			a--; b--;

			w[a].push_back(make_pair(b,c));
			u[b].push_back(make_pair(a,c));

		}

		int z = 0;

		// forward dijkstra
		{
			priority_queue<nod> q;
			for (int i = 0 ; i < n; i++) v[i] = BIG;

			q.push(nod(0,0));
			v[0] = 0;

			while (!q.empty()) {
				nod t = q.top();
				q.pop();


				for (vector<pair<int,int> >::iterator it = w[t.k].begin(); it != w[t.k].end(); it++) {
					if (v[it->first] <= t.v + it->second) continue;
					q.push(nod(it->first, t.v+it->second));
					v[it->first] = t.v+it->second;
				}
			}

			for (int i = 0 ; i < n; i++) {
				z += v[i];
			}
		}
		
		// backward dijkstra
		priority_queue<nod> q;
		for (int i = 0 ; i < n; i++) v[i] = BIG;

		q.push(nod(0,0));
		v[0] = 0;

		while (!q.empty()) {
			nod t = q.top();
			q.pop();


			for (vector<pair<int,int> >::iterator it = u[t.k].begin(); it != u[t.k].end(); it++) {
				if (v[it->first] <= t.v + it->second) continue;
				q.push(nod(it->first, t.v+it->second));
				v[it->first] = t.v+it->second;
			}
		}

		for (int i = 0 ; i < n; i++) {
			z += v[i];
		}

		printf("%d\n", z);
	}


}
