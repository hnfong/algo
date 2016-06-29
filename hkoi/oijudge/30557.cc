#include <stdio.h>
#include <string.h>
//#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct nod {
	int v,e;
};
int n;

int en[100];
//int w[100][100];
bool h[101*101*101];
queue<nod> q;
vector<int> l[100];

int push(int v, int e) {
	if (e <= 0) return false;
	if (e > n*100) return false;
	if (h[e*100+v]) return false;
	h[e*100+v] = 1;
	nod tmp;
	tmp.v = v;
	tmp.e = e;
	q.push(tmp);
	return true;
};

nod pop() {
	nod tmp = q.front();
	q.pop();
	return tmp;
};

int main() {
//	while (true) {
		scanf("%d", &n);
//		if (n == -1)  break;
		memset(h,0,sizeof(h));
		//memset(w,0,sizeof(w));
		memset(en,0,sizeof(en));
		for (int i = 0 ; i < 100; i ++ ) {
			l[i].clear();
		};
		while (!q.empty()) q.pop();
		for (int i = 0 ; i < n ;  i ++ ) {
			int k;
			scanf("%d %d ", &en[i], &k);
			for (int j = 0 ; j < k ; j ++ ) { 
				int x;
				scanf("%d", &x);
				//w[i][x-1] = 1;
				l[i].push_back(x-1);
				//w[x-1][i] = 1;
				//l[x-1].push_back(i);
			};
		};

		bool found = false;
		push(0,100);
		while (!q.empty()) {
			nod tmp = pop();
			if (tmp.v == n-1) { found = true; break; };
			for (vector<int>::iterator it = l[tmp.v].begin() ; it != l[tmp.v].end(); it++ ) {
				push(*it, tmp.e + en[*it]);
			};
		};
		if (found) {
			printf("winnable\n");
		} else {
			printf("hopeless\n");
		};
//	};
};

