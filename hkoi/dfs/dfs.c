#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

#define mytrue 1
#define myfalse 0
#define wrong -1
#define current 2

#define init(a) memset (a, 0, sizeof(a))

int x;
int y;
char s[200][200];
int m[200][200];
int d[4][2] = { {0,1} , {0,-1} , {1,0} , {-1,0} };
int h[300][2][2];

typedef struct {
	signed int x;
	signed int y;
} coords ;


void dump() {
	int i,j;
	clear();
	for (j=0;j<y;j++) {
		for (i=0;i<x;i++) {
			if (m[j][i] == current) {
				printw("@");
			} else if (m[j][i] == mytrue && s[j][i] == ' ') {
				printw(".");
			} else if (m[j][i] == wrong && s[j][i] == ' ') {
				printw("x");
			} else {
				printw("%c", s[j][i]);
			};
		};
		printw("\n");
	};
	refresh();
};
int dfs (int a, int b) {
	int i,j,r,t;
	if (s[b][a] == '#') { return 0; };
	if (m[b][a] != myfalse) { return 0; };
	m[b][a] = current;
	dump();
	usleep(50000);
	m[b][a] = mytrue;
	if (s[b][a] == 'Z') { return 1; };
	if (s[b][a] >= 'A' && s[b][a] < 'Z') {
		for (i=0;i<2;i++) {
			if (dfs(h[s[b][a]-64][i][0], h[s[b][a]-64][i][1]) == 1) {return 1; } ;
		};
	};
	r = 0;
	for (i=0;i<4;i++) {
		while (mytrue) {
			j=1+(int) (4.0*rand()/(RAND_MAX+1.0));
			t = 1 << j;
			if ((r & t) == 0) {
				r = (r | t);
				break;
			};
		};
		if (dfs(a + d[j][0], b + d[j][1]) == 1) {return 1;};
	};
	m[b][a] = current;
	dump();
	usleep(50000);
	m[b][a] = wrong;
	return 0;
};

coords simove(int a, int b, int k) {
	coords ret;
	ret.x = -1;
	ret.y = -1;
	if (k == KEY_LEFT) { a --; };
	if (k == KEY_RIGHT) { a ++; };
	if (k == KEY_UP) { b --; };
	if (k == KEY_DOWN) { b ++; };

	if (s[b][a] == '#') { return ret; };
	if (s[b][a] == 'Z') { ret.x = -2; return ret; };
	if (s[b][a] >= 'A' && s[b][a] < 'Z') {
		if (a == h[s[b][a]-64][0][0] && b == h[s[b][a]-64][0][1]) {
			ret.x = h[s[b][a]-64][1][0];
			ret.y = h[s[b][a]-64][1][1];
		} else {
			ret.x = h[s[b][a]-64][0][0];
			ret.y = h[s[b][a]-64][0][1];
		};
		a = ret.x;
		b = ret.y;
	};
	m[b][a] = current;
	dump();
	m[b][a] = myfalse;
	ret.x = a;
	ret.y = b;
	return ret;
}

int main() {
	int i,j,k;
	coords t;
	FILE *fp;
	int seed;
	int seed2;
	initscr(); cbreak(); noecho();
	nonl();
	keypad(stdscr, TRUE);
	intrflush(stdscr, FALSE);
	fp = fopen("/dev/random", "r");
	seed = fgetc(fp);
	seed <<= 8;
	seed2 = fgetc(fp);
	seed = seed + seed2;
	printf("%d", seed);
	srand(seed);
	fclose(fp);
	
	memset(s, '#', 10000);
	init(m);
	init(h);
	fp = fopen("maze.txt", "r");
	if (fp == NULL ) {printf ("test"); };
	fscanf(fp , "%d %d\n", &x, &y);
	for (i=0;i<y;i++) {
		if (feof(fp)) {return 1;};
		fgets(s[i], x+2, fp);
		s[i][x] = '\0';
	};
	fclose(fp);

	// process
	for (i=0;i<x;i++) {
		for (j=0;j<y;j++) {
			if (s[j][i] >= 'A' && s[j][i] < 'Z') {
				if (h[s[j][i]-64][0][0] == 0) {
					h[s[j][i]-64][0][0] = i;
					h[s[j][i]-64][0][1] = j;
				} else {
					h[s[j][i]-64][1][0] = i;
					h[s[j][i]-64][1][1] = j;
				};
			};
		};
	};
	dump();
	i=1;
	j=1;
	while (true) {
		k = getch();
		if (k == 27) {
			break; 
		};
		t = simove(i,j,k);
		if (t.x > 0 ) {
			i = t.x;
			j = t.y;
		} else if (t.x == -2 ) {
			printw("You found it!!!");
			refresh();
			getch();
			break;
		};
	};
	if (dfs(1,1) == 0) { printf("No solution!\n"); };
//	dump();
	return 0;
};

