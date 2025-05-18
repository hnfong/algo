/*
@JUDGE_ID: 20044WC 10107 C "Two Heaps"
 */

#include <stdio.h>

int l[5001];
int r[5001];

int cmp(int a, int b, int op) {
	if (op == 1) return a > b;
	if (op == 2) return b > a;
};

void heapadd(int *h, int v, int op) {
	int i;
	i = ++h[0];
	while (i>1 && cmp(v,h[i/2],op)) {
		h[i] = h[i/2];
		i = i / 2;
	};
	h[i] = v;
};

int heappop(int *h, int op) {
	int r;
	int i;
	int l,t;
	r = h[1];
	h[1] = h[h[0]];
	h[0]--;
	i = 1;
	while (1) {
		l = i;
		if ((i*2<=h[0]) && cmp(h[i*2], h[l], op)) l = i*2;
		if ((i*2+1<=h[0]) && cmp(h[i*2+1],h[l],op)) l = i*2+1;
		if (l==i) break;
		t = h[l];
		h[l] = h[i];
		h[i] = t;
		i = l;
	};
	return r;
};

int main () {
	int i,j,m,v,n;
	l[0]=0;
	r[0]=0;
	scanf("%d\n", &m);
	printf("%d\n", m);
	n = 1;
	while (! feof(stdin)) {
		n++;
		scanf("%d\n", &v);
		if (v>=m) heapadd(r,v,2);
		if (v<m) heapadd(l,v,1);

		if (l[0]>r[0]) {
			heapadd(r,m,2);
			m = heappop(l,1);
		};
		if (r[0]-1>l[0]) {
			heapadd(l,m,1);
			m = heappop(r,2);
		};
		if (n % 2 == 1) printf("%d\n", m);
		else printf("%d\n", (m+r[1])/ 2); 
	};
	return 0;
};

