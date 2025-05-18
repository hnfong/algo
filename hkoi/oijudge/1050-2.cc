#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int vol[40];
int binsum[40];
int loc[40];
int n;
int c;
int e[40];

int best;

bool cmp ( int a , int b ) { return a > b; };
void dump() {
	for (int i = 0; i <= best ; i ++ ) {
		printf("%d ", binsum[i]);
	}; printf("\n");
};

bool put(int o, int b) {
	if (binsum[b] + vol[o] > c) return false;
	if (e[b] < vol[o]) return false;
	if (loc[o] == b) return false;
	//printf("Put %d[%d] from bin(%d) into %d[%d]\n", o, vol[o], loc[o], b, binsum[b]);
	binsum[loc[o]] -= vol[o];
	binsum[b] += vol[o];
	if (best == loc[o] && binsum[loc[o]] == 0) {
		best = loc[o] - 1;
		/*printf("BEST ! %d\n", best);
		dump();*/
	};
	loc[o] = b;
	//dump();
	return true;
};
int limit;

int cnt = 0;
int recur(int o) {
	for (int i = 0; i < o ; i ++ ) {
		int k = loc[i];
		cnt ++ ;
		if (cnt > 60000000) break;
		if (put(o,i)) {
			int t = e[i];
			e[i] = vol[o];
			recur(o-1);
			put(o,k);
			e[i] = t;
		};
		if (i >= best) break;
	};

	return 0;
};

int sum() {
	int z = 0;
	for (int i = 0 ; i <= best; i ++ ) {
		z += binsum[i];
	};
	return z;
};

int svol[40];
int sbinsum[40];
int sloc[40];
int se[40];

int main()  {
	int z = 0;
	memset(vol,0,sizeof(vol));
	scanf("%d %d", &n, &c);
	best = n -1 ;
	for (int i = 0 ; i < n ;  i ++ ) {
		scanf("%d", &vol[i]);
		e[i] = 999999;
	};
	sort(vol,vol+n,cmp);
	for (int i = 0 ; i < n ;  i ++ ) {
		z += vol[i];
		binsum[i] = vol[i];
		loc[i] = i;
	};


	//for (best = z / c - 1; best < n-1; best ++ ) {
		// save
		/*memcpy(svol,vol, sizeof(vol));
		memcpy(sbinsum,binsum, sizeof(binsum));
		memcpy(se,e, sizeof(e));
		memcpy(sloc,loc, sizeof(loc));*/
		recur(n-1);
		//if (sum() == z) break;
		/*memcpy(vol,svol, sizeof(vol));
		memcpy(binsum,sbinsum, sizeof(binsum));
		memcpy(e,se, sizeof(e));
		memcpy(loc,sloc, sizeof(loc));*/
	//};
	printf("%d\n", best+1);

	return 0;
};
