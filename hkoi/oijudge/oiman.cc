#include <stdio.h>
#include <string.h>
#define SIZ 22

int map[SIZ][SIZ];
bool used[SIZ][SIZ][6][6];
int map_w, map_h;
int bombs;
int duration;

struct nod {
	int r,c,b, bt, t;
};

nod q[SIZ*SIZ*37];
int qh = 0, qt = 0;

bool go(int r, int c, int b, int bt, int t) {
	if (! ( r >= 0 && r < map_h && c >= 0 && c < map_w ) ) { return false; };
	if (map[r][c] == 'W') { return false; };
	if (map[r][c] == 'M' || map[r][c] == 'V') {
		if (t == 0) {
			b--;
			if (b < 0) return false;
			t = duration;
		};
	};
	if (t > 0) t--;
	if (used[r][c][b][t]) return false;
	qt++;
	q[qt].r = r;
	q[qt].c = c;
	q[qt].b = b;
	q[qt].bt = bt;
	q[qt].t = t;
	used[r][c][b][t] = true;
	return true;
};

nod pop() {
	qh++;
	return(q[qh]);
};


int main() {
	int initr,initc, endr,endc;
	memset(used,0,sizeof(used));
	scanf("%d %d\n%d\n", &bombs, &duration, &map_h);
		map_w = map_h;
		int c;
		while( (c = getc(stdin)) == '\n' || c == 13 );
		ungetc(c, stdin);
	for (int i = 0; i < map_h ; i++ ) {
		for (int j = 0 ; j < map_w ; j++ ) {
			map[i][j] = getc(stdin);
			if (map[i][j] == 'O') {
				initr = i;
				initc = j;
			};
			if (map[i][j] == 'V') {
				endr = i;
				endc = j;
			};
		};
		int c;
		while( (c = getc(stdin)) == '\n' || c == 13 );
		ungetc(c, stdin);
	};

	qh = qt = 0;

	go(initr,initc,bombs, 0, 0);
	while (qh<qt) {
		nod n;
		n = pop();
		if (n.r == endr && n.c == endc) break;
		go(n.r+1, n.c, n.b, qh, n.t);
		go(n.r-1, n.c, n.b, qh, n.t);
		go(n.r, n.c+1, n.b, qh, n.t);
		go(n.r, n.c-1, n.b, qh, n.t);
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

	//printf("%d %d\n", initr+1, initc+1);

	while ( k > 0 ) {
		k --;
		//printf("%d %d\n", ans[k][0]+1, ans[k][1]+1);
	};
};


