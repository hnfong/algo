#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node { 
	int v;
	int f;
	struct node *n;
};

#define HASHSIZE 999997
struct node *h[HASHSIZE];

int power(int x, int n) {
	if (n == 0) return 1;
	int c;
	c = power(x, n/2);
	if (n % 2 == 0) { return (c * c ); } else { return (c * c * x) ; };
};

void insert(int n) {
	int k;
	struct node *p;
	struct node *l;
	
	k = abs(n % HASHSIZE);
	if (h[k] != NULL) {
		p = h[k];
		while (p != NULL) {
			l = p; p = p->n;
			if (l->v == n) {
				l->f++;
				return;
			};
		};
		l->n = ( struct node * ) malloc(sizeof (struct node));
		l->n->v = n;
		l->n->n = NULL;
		l->n->f = 1;
	} else {
		h[k] = ( struct node * ) malloc(sizeof (struct node));
		h[k]->v = n;
		h[k]->f = 1;
		h[k]->n = NULL;
	};
};

int exists(int n) {
	int k;
	struct node *p;
	k = abs(n % HASHSIZE);
	p = h[k];
	while (p != NULL) {
		if (p->v == n) { return p->f; }  else { p = p->n; };
	};
	return 0;
};


int main() {
	int n, p[7], m, k[7];
	int i, z, c, o;
	int x[7];
	int t;

	memset(h, 0, sizeof(h));


	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0 ; i < n ; i ++ ) { 
		scanf("%d %d", &k[i], &p[i]);
	};

	if (n == 1) {
		if (k == 0) {
			printf("%d\n", 0);
		} else {
			printf("%d\n", 0);
		};
		return 0;
	};
	
	c = 0;

	/* LHS */
	x[0] = x[1] = x[2] = x[3] = x[4] = x[5] = x[6] = 0;
	x[0] = 1;
	t = (n+1)/2;
	while (x[t] == 0) {
		z = 0;
		for (i=0;i<t;i++) 
			z += k[i]*power(x[i], p[i]);
		insert(z);
		// printf("%d %d %d %d %d %d\n", x[0], x[1], x[2], x[3], x[4], x[5]);
		x[0]++;
		for (i=0;i<t;i++) {
			if (x[i] > m) {
				x[i+1]++;
				x[i]-= m;
			};
		};
	};
	
	/* RHS */
	x[0] = x[1] = x[2] = x[3] = x[4] = x[5] = x[6] = 0;
	x[0] = 1;
	t = n/2;
	o = (n+1)/2 ;
	while (x[t] == 0) {
		z = 0;
		for (i=0;i<t;i++) 
			z += k[i+o]*power(x[i], p[i+o]);
		c += exists(-z);
		// printf("%d %d %d %d %d %d\n", x[0], x[1], x[2], x[3], x[4], x[5]);
		x[0]++;
		for (i=0;i<t;i++) {
			if (x[i] > m) {
				x[i+1]++;
				x[i]-= m;
			};
		};
	};
	printf("%d\n", c);
	return 0;
};

