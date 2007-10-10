#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct nod {
	nod(int kk,int vv){
		this->k = kk;
		this->v = vv;
	}
	int k,v;
	int operator<(const nod &b) const {
		return this->v > b.v;
	}
};


struct m_edge { // meta edge... it generates the edges
	int weight;
	int yes_mask, no_mask;
	int fix_mask, break_mask;

	m_edge(int w, const char *prereq, const char *action)
	{
		this->weight = w;
		this->yes_mask = this->no_mask = this->fix_mask = this->break_mask = 0;
		for (const char *c = prereq; *c != 0; c++) {
			this->yes_mask <<= 1;
			this->no_mask <<= 1;

			if (*c == '+') { this->yes_mask += 1; }
			if (*c == '-') { this->no_mask += 1; }
		}

		for (const char *c = action; *c != 0; c++) {
			this->fix_mask <<= 1;
			this->break_mask <<= 1;

			if (*c == '+') { this->fix_mask += 1; }
			if (*c == '-') { this->break_mask += 1; }
		}
	}

	bool can_use_edge(int k) {
		// printf("[k = %x, ~k = %x, yes = %x, no = %x, k&yes = %x, ~k&no = %x]\n", k, ~k, this->yes_mask, this->no_mask, (k & this->yes_mask), ((~k) & this->no_mask));
		return ( (k & this->yes_mask) == this->yes_mask) && ( ((~k) & this->no_mask) == this->no_mask);
	}

	int transform(int k) {
		return (k | this->fix_mask) & (~this->break_mask);
	}
};

#define BIG 100000000

int main()
{
	int n,m,cse = 0;
	while (scanf("%d %d", &n, &m), n) {
		priority_queue<nod> q;
		vector <m_edge> e;
		int v[1024*1024];

		for (int i = 0 ; i < 2 << (n - 1);i++) v[i] = BIG;

		int a;
		char b[30];
		char c[30];

		for (int i = 0 ; i < m; i++) {
			scanf("%d %s %s\n", &a, (char*)&b, (char*)&c);
			e.push_back(m_edge(a,b,c));
		}

		int start = 0;
		for (int i = 0 ; i < n; i++) { 
			start <<= 1;
			start += 1;
		}

		q.push(nod(start,0));

		while (!q.empty()) {
			nod t = q.top();
			q.pop();

			// printf("%x %x\n", t.k, t.v);
			if (t.k == 0) break;

			for (vector <m_edge>::iterator it = e.begin(); it != e.end(); it ++ ){
				// printf("%d %d %d\n", it->yes_mask, it->no_mask, it->can_use_edge(t.k));
				if (it->can_use_edge(t.k)) {
					int c = it->transform(t.k);
					if (v[c] <= t.v+it->weight) continue;

					// printf("pushing %d as value %d\n", c,t.v+it->weight);

					q.push(nod(c, t.v+it->weight));
					v[c] = t.v+it->weight;
				}
			}
		}

		printf("Product %d\n", ++cse);
		if (v[0] != BIG) {
			printf("Fastest sequence takes %d seconds.\n", v[0]);
		} else {
			printf("Bugs cannot be fixed.\n");
		}
		printf("\n");
	}
}
