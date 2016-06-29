#include <stdio.h>
#include <string.h>
#define SIZ 22

int map[SIZ][SIZ];
bool used[SIZ][SIZ][3];
int map_w, map_h;
int bombs;

struct nod {
	int r,c,b, bt;
};

nod q[SIZ*SIZ*3+2];
int qh = 0, qt = 0;

bool go(int r, int c, int b, int bt) {
	if (! ( r > 0 && r <= map_h && c > 0 && c <= map_w ) ) { return false; };
	if (used[r][c][b]) return false;
	if (map[r-1][c-1] == '1') { b--; if (b < 0) return false; };
	qt++;
	q[qt].r = r;
	q[qt].c = c;
	q[qt].b = b;
	q[qt].bt = bt;
	used[r][c][b] = true;
	return true;
};

nod pop() {
	qh++;
	return(q[qh]);
};


int main() {
	memset(used,0,sizeof(used));
	scanf("%d %d %d", &bombs, &map_h, &map_w);
		int c;
		while( (c = getc(stdin)) == '\n' || c == 13 );
		ungetc(c, stdin);
	for (int i = 0; i < map_h ; i++ ) {
		for (int j = 0 ; j < map_w ; j++ ) {
			map[i][j] = getc(stdin);
		};
		int c;
		while( (c = getc(stdin)) == '\n' || c == 13 );
		ungetc(c, stdin);
	};

	qh = qt = 0;

	go(1,1,bombs, 0);
	while (qh<qt) {
		nod n;
		n = pop();
		if (n.r == map_h && n.c == map_w) break;
		go(n.r+1, n.c, n.b, qh);
		go(n.r-1, n.c, n.b, qh);
		go(n.r, n.c+1, n.b, qh);
		go(n.r, n.c-1, n.b, qh);
	};

	nod n = q[qh];

	int ans[SIZ*SIZ][2];
	int k  =0 ;

	while (n.bt != 0) {
		ans[k][0] = n.r;
		ans[k][1] = n.c;
		k ++;
		n = q[n.bt];
	};

	printf("%d\n", k);
	printf("1 1\n");

	while ( k > 0 ) {
		k --;
		printf("%d %d\n", ans[k][0], ans[k][1]);
	};
};


