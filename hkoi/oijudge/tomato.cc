#include <stdio.h>
#include <string.h>
#include <algorithm>

int w[10000];
int r[10000];
int a[10000];

int main() {
	int t,m,n;
	memset(w,0,sizeof(w));
	memset(r,0,sizeof(r));
	
	scanf("%d %d %d\n", &n, &t, &m);
	for (int i = 0 ; i < m ; i ++ ) { 
		scanf("%d", &a[i]);
	};

	std::sort(a,a+m);

	for (int i = 1 ; i < m ; i ++ ) {
		int k = a[i] - a[i-1] - 1;
		if (k/2 < 10000) {
			w[k/2]+=2;
			r[k/2] += (k % 2);
		};
	};
	
	if (a[0]-1 < 10000) {
		w[a[0]-1]++;
	};
	if (n-a[m-1] < 10000) {
		w[n-a[m-1]]++;
	};

	/*for (int i = 0 ; i < n ; i ++ ) {
		printf("%d %d %d\n", i, w[i], r[i]);
	};*/

	int bad = m; // when t = 0;
	int inc = 2*m; // increment each time
	
	for (int i = 0 ; i < t ; i++ ) {
		inc -= w[i];
		bad += inc + r[i];
		printf("%d\n", bad );
	};
};

