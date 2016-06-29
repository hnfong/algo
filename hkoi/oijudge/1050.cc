#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int vol[40];
int loc[40];
int binsum[40];
int e[40];
int f[40];
int c;
int n;
int curbin = 0;
bool debug = false;

int best = 40;

bool cmp ( int a , int b ) { return a > b; };


void dumpconf() {
	for (int i = 0; i < n; i ++ ) {
		printf("%.3d ", vol[i]);
	}; printf("\n");
	for (int i = 0; i < n; i ++ ) {
		printf("%.3d ", loc[i]);
	}; printf("\n");
	for (int i = 0; i < n; i ++ ) {
		printf("%.3d ", binsum[i]);
	}; printf("\n");
};

int recur(int o) {
	printf("%d\n", o);
	int t;
	if (debug) printf("%d %d\n", o, curbin);
	if (loc[o] != -1) return -1;

	if (binsum[curbin] + vol[o] > c) {
		if (vol[o] > f[curbin]) { return -1; };
		curbin ++;
		f[curbin] = vol[o];
	};
	if (curbin >= best) goto skip2;

	if (e[curbin] < vol[o]) { goto skip2; };

	t = e[curbin]; // save it up
	e[curbin] = vol[o];

	binsum[curbin] += vol[o];
	loc[o] = curbin;

	if (count(loc, loc+n,  -1) == 0) {
		best = curbin;
		printf("Best: %d\n", curbin+1);
		dumpconf();
		goto skip;
	};

	for (int i = 0; i < n ; i ++ ) {
		recur(i);
	};

	skip:


	e[curbin] = t;

	loc[o] = -1;
	binsum[curbin] -=  vol[o];

	skip2:

	if (binsum[curbin] == 0) {
		curbin -- ;
	};
	return 0;
};

int main()  {
	memset(vol,0,sizeof(vol));
	memset(binsum,0,sizeof(binsum));
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i  ++ ) { loc[i] = -1; };
	for (int i = 0; i < n; i  ++ ) { e[i] = 2147483647; };
	for (int i = 0 ; i < n ;  i ++ )
		scanf("%d", &vol[i]);
	sort(vol,vol+n,cmp);
	//for ( int i = 0 ; i < n ; i ++ ) { printf("%d\n", vol[i]); };

	f[0] = vol[0];
	recur(0);
	printf("\n");
	dumpconf();

	return 0;
};

