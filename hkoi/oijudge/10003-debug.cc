#include <stdio.h>
#include <string.h>

struct guardstruct { int r,c,p; char d; };

struct nod {
	char r[2],c[2];
	int t;
	int bt;
	char d;
};

#define debug(x) printf("DEBUG[%d]\n", x)

//#define DEBUG
#ifdef DEBUG
#define dprintf printf
#else
#define dprintf(...)
#endif

char map[2][20][20];
int row[2];
int col[2];
int gnum[2];
char used[21][21][21][21][12];
nod q[20*20*20*20*12+1];

int qh,qt;

guardstruct g[2][10];

int offset(int m, int i, int t) {
	int p = (g[m][i].p-1)*2;
	int x = t % p;
	if (x < (p/2)) {
		// 1st half
		return x;
	} else {
		return g[m][i].p-(x-p/2)-1;
	};
};

bool push(int a,int b,int c,int d,int t, char s) {
	int old_a = a; int old_b = b; int old_c = c; int old_d = d;
	if (s == 'N') {
		if (a == 0) { a = 20; b = 20; };
		if (c == 0) { c = 20; d = 20; };
		if (a!=20 && map[0][a-1][b]=='.') { a--; };
		if (c!=20 && map[1][c-1][d]=='.') { c--; };
	};
	if (s == 'S') {
		if (a == row[0]-1) { a = 20; b = 20; };
		if (c == row[1]-1) { c = 20; d = 20; };
		if (a!=20 && map[0][a+1][b]=='.') { a++; };
		if (c!=20 && map[1][c+1][d]=='.') { c++; };
	};
	if (s == 'W') {
		if (b == 0) { a = 20; b = 20; };
		if (d == 0) { c = 20; d = 20; };
		if (b!=20 && map[0][a][b-1]=='.') { b--; };
		if (d!=20 && map[1][c][d-1]=='.') { d--; };
	};
	if (s == 'E') {
		if (b == col[0]-1) { a = 20; b = 20; };
		if (d == col[1]-1) { c = 20; d = 20; };
		if (b!=20 && map[0][a][b+1]=='.') { b++; };
		if (d!=20 && map[1][c][d+1]=='.') { d++; };
	};

	if (! (( (a >= 0 && a < row[0]) || a == 20) && ((b >= 0 && b < col[0]) || b==20) &&\
		 (c >= 0 && c < row[1]) || c == 20) && ((d >= 0 && d < col[1]) || d==20) ){ 
		return false;
	};

	if (used[a][b][c][d][t]) { return false; };

	for (int i = 0 ; i < gnum[0] ; i++ ) { //foreach guard
		int o = offset(0,i,t);
		int gr, gc;
		gr = g[0][i].r-1;
		gc = g[0][i].c-1;
		if (g[0][i].d == 'N') gr -= o;
		if (g[0][i].d == 'S') gr += o;
		if (g[0][i].d == 'W') gc -= o;
		if (g[0][i].d == 'E') gc += o;
		dprintf("%d guard %d: %d %d [%d] %d\n", 0, i, gr,gc ,o,t);
		if (gr == a && gc == b) {
			dprintf("collision\n");
			return false;
		};

		// check swap
		if (old_a == gr && old_b == gc) {
			o = offset(0,i, (t+11)%12 );
			gr = g[0][i].r-1;
			gc = g[0][i].c-1;
			if (g[0][i].d == 'N') gr -= o;
			if (g[0][i].d == 'S') gr += o;
			if (g[0][i].d == 'W') gc -= o;
			if (g[0][i].d == 'E') gc += o;
			if (gr == a && gc == b) {
				dprintf("collision swap!");
				return false;
			};
		};
	};
	for (int i = 0 ; i < gnum[1] ; i++ ) { //foreach guard
		int o = offset(1,i,t);
		int gr, gc;
		gr = g[1][i].r-1;
		gc = g[1][i].c-1;
		if (g[1][i].d == 'N') gr -= o;
		if (g[1][i].d == 'S') gr += o;
		if (g[1][i].d == 'W') gc -= o;
		if (g[1][i].d == 'E') gc += o;
		dprintf("%d guard %d: %d %d [%d] %d\n", 0, i, gr,gc ,o,t);
		if (gr == c && gc == d) {
			dprintf("collision\n");
			return false;
		};

		// check swap
		if (old_c == gr && old_d == gc) {
			o = offset(1,i, (t+11)%12 );
			gr = g[1][i].r-1;
			gc = g[1][i].c-1;
			if (g[1][i].d == 'N') gr -= o;
			if (g[1][i].d == 'S') gr += o;
			if (g[1][i].d == 'W') gc -= o;
			if (g[1][i].d == 'E') gc += o;
			if (gr == c && gc == d) {
				dprintf("collision swap!");
				return false;
			};
		};
	};
	
	dprintf("%d %d %d %d %d %c\n", a,b,c,d,t,s);
	
	//if (map[0][a][b] == '#' || map[1][c][d] == '#') return false;
	used[a][b][c][d][t] = true;
	qt++;
	q[qt].r[0] = a;
	q[qt].c[0] = b;
	q[qt].r[1] = c;
	q[qt].c[1] = d;
	q[qt].d = s;
	q[qt].bt = qh;
	q[qt].t = t;
	return true;
};

nod pop() {
	qh++;
	return q[qh];
};

int main() {
	int ir[2],ic[2];
#ifdef DEBUG
	printf("%d %d\n", sizeof(q), sizeof(used));
#endif
	memset(used,0,sizeof(used));

	qt = 0;
	qh = 0;

	for (int z = 0; z < 2 ; z++ ) {
		scanf("%d %d\n", &row[z], &col[z]);
		
		for (int i = 0 ; i < row[z]; i++ ) {
			for (int j = 0 ; j < col[z] ; j++ ) {
				map[z][i][j] = getc(stdin);
				if (map[z][i][j] == 'X') {
					ir[z] = i;
					ic[z] = j;
					map[z][i][j] = '.';
				};
			};
			scanf("\n");
		};

		scanf("%d\n", &gnum[z]);
		for (int i = 0; i < gnum[z]; i++ ) {
			scanf("%d %d %d %c\n", &g[z][i].r, &g[z][i].c , &g[z][i].p, &g[z][i].d );
		};
	};

	bool found = false;
	push(ir[0],ic[0],ir[1],ic[1], 0, '@');
	while (qh != qt) {
		nod t = pop();
		if (t.r[0] == 20 && t.c[0] == 20 && t.r[1] == 20 && t.c[1] == 20) {
#ifdef DEBUG
			printf("FOUND SAI %d %d %d %d!!\n", t.r[0], t.c[0], t.r[1], t.r[1]);
#endif
			found = true;
			break;
		};
#ifdef DEBUG
		printf("%d %d\n", qh, qt);
#endif
		push(t.r[0],t.c[0],t.r[1],t.c[1], (t.t+1) % 12, 'N');
		push(t.r[0],t.c[0],t.r[1],t.c[1], (t.t+1) % 12, 'E');
		push(t.r[0],t.c[0],t.r[1],t.c[1], (t.t+1) % 12, 'S');
		push(t.r[0],t.c[0],t.r[1],t.c[1], (t.t+1) % 12, 'W');
	};
	if (!found) {
		printf("-1\n");
		return 0;
	};
#ifdef DEBUG
	printf("finished bfs\n");
#endif

	nod t = q[qh];

	char aaa[10001];

	int k = 0;

	while (t.bt != 0) {
#ifdef DEBUG
		printf("%d %d %d %d %c\n", t.r[0], t.c[0], t.r[1], t.c[1], t.d);
#endif
		aaa[k] = t.d;
		k ++;
		t = q[t.bt];
	};
#ifdef DEBUG
	printf("%d %d %d %d %c\n", t.r[0], t.c[0], t.r[1], t.c[1], t.d);
#endif

	printf("%d\n", k);
	while (k > 0) {
		k--;
		printf("%c\n", aaa[k]);
	};
};

