#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
}	loc ;

int m[31][31];
int ed[31][31];
loc w[128][4];
loc q[10000];

void addq (int x, int y) {
	static p;
	p++;
	printf("%d/%d ", x, y);
	q[p].x = x;
	q[p].y = y;
	ed[x][y] = 1;
};
loc getq () {
	static p2;
	p2++;
	return q[p2];
};

int main() {
	int x;int y;
	int a;int b;
	int i;int j;int k;
	loc tl;
	FILE *fp;
	/* init */
	for (i=0;i<=128;i++) {
		w[i][0].x = 0;
	};
	memset(&ed, 0, sizeof(ed));

	/* start of input */
	fp = fopen("input.txt", "r");
	if (fp == NULL ) {printf("failed opening file");return 1;};
	fscanf(fp, "%d %d\n", &a, &b);

	/* fill the map first (used to fill the walls mainly */
	for (j=0;j<=b+1;j++) {
		for (i=0;i<=a+1;i++) {
			m[i][j] = 49;
		};
	};
	for (j=1;j<=b;j++) {
		for (i=1;i<=a;i++) {
			fscanf(fp, "%c\n", &m[i][j]);
			if (m[i][j] > 58) {
				w[m[i][j]][0].x++;
				w[m[i][j]][w[m[i][j]][0].x].x = i;
				w[m[i][j]][w[m[i][j]][0].x].y = j;
			};
			printf("%d ", m[i][j]);
		};
		printf("\n");
	};
	//test 
	/* Process */
	addq(a,b);
	while ((tl=getq()).x >=0) {
		x = tl.x;
		y = tl.y;
		if (m[x][y] > 49) {
/*			printf("(processing wormhole %c", m[x][y]);*/
			for (i=1;i<=w[m[x][y]][0].x;i++) {
				if (x != w[m[x][y]][i].x && y != w[m[x][y]][i].y && w[m[x][y]][i].x != 0 && ed[w[m[x][y]][i].x][w[m[x][y]][i].y] == 0) {
/*					printf(" from %d %d to %d %d", x , y, w[m[x][y]][i].x, w[m[x][y]][i].y);*/
					addq(w[m[x][y]][i].x, w[m[x][y]][i].y);
					w[m[x][y]][i].x = 0;
				};
			};
/*			printf(")");*/
		};
		if (m[x+1][y] != 49 && ed[x+1][y] == 0) {addq(x+1, y);};
		if (m[x-1][y] != 49 && ed[x-1][y] == 0) {addq(x-1, y);};
		if (m[x][y+1] != 49 && ed[x][y+1] == 0) {addq(x, y+1);};
		if (m[x][y-1] != 49 && ed[x][y-1] == 0) {addq(x, y-1);};
		if (x == 1 && y == 1) { printf("done\n"); break;};
	};
	close(fp);
	return 0;
};
