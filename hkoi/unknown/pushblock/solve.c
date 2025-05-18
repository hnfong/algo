#include <stdio.h>
#include <stdlib.h>

int map [10][10] = {	
			1,1,1,1,1,1,1,1,1,1,
			1,0,0,0,0,0,0,0,1,1,
			1,0,1,0,1,1,1,1,0,1,
			1,0,0,1,0,0,0,0,0,1,
			1,0,0,0,0,0,1,0,0,1,
			1,0,0,0,0,1,0,0,0,1,
			1,0,1,0,0,0,1,0,0,1,
			1,0,0,1,0,0,0,0,0,1,
			1,0,1,0,1,0,1,0,0,1,
			1,1,1,1,1,1,1,1,1,1
};

int dir[4][2] = { 1, 0,  0, 1, -1, 0, 0, -1};
int mark[10][10];

typedef struct {
	int x;
	int y;
} loc;


int havepath(loc from, loc to) {
	loc l;
	int i;
	int tmp;
	mark[from.x][from.y] = 1;

	if (from.x == to.x && from.y == to.y) {printf("found!\n");return 1;};
	/*if (map[from.x][from.y] == 9) {printf("found!\n");return 1;};*/
	for (i=0;i<4;i++) {
		l.x = from.x + dir[i][0];
		l.y = from.y + dir[i][1];
		if (map[l.x][l.y] == 0 && mark[l.x][l.y] == 0) {
			tmp = havepath(l , to);
			if (tmp > 0) {return tmp + 1;};
		};
	};
	mark [from.x][from.y] = 0;
	return 0;
};

int dumpmark() {
	int i,j;
	for (i=0;i<10;i++) {
		for (j=0;j<10;j++) {
			printf("%d", mark[i][j]);
		};
		printf("\n");
	};
};

int main() {
	loc l1, l2;
	l1.x = 1;
	l1.y = 1;
	l2.x = 8;
	l2.y = 8;
	memset(mark, 0, sizeof(mark));
	printf("number of paths taken %d\n", havepath(l1, l2));
	dumpmark();
	return 0;
};

