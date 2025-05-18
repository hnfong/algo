#include <stdio.h>
#include <string.h>

int qx[100000];
int qy[100000];
int qh, qt;

char w[101][101];
int d[101][101];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void enqueue(int x, int  y, int z) {
	if (w[x][y] == '#') return;
	if (d[x][y] != -1) return;
	qx[qt] = x;
	qy[qt] = y;
	d[x][y] = z;
	qt++;
}

void dequeue(int *x, int *y, int *z) {
	*x = qx[qh];
	*y = qy[qh];
	*z = d[*x][*y];
	qh++;
}

int main() {
	int n, m;
	int i,j,k;
	int tx,ty;
	char s[1000];
	scanf("%d %d\n", &n, &m);
	for (i = 0 ;i < n ; i ++ ) {
		gets(s);
		for (j = 0 ; j < strlen(s); j++) {
			w[i][j] = s[j];
			d[i][j] = -1;
		}
	}

	// find exit
	
	for (i = 0 ; i < n; i++)  {
		for (j = 0 ; j < m; j++) {
			if (w[i][j] == 'E') {
				enqueue(i,j, 0);
			}
		}
	}

	while (qh != qt) {
		int a, b, c;
		dequeue(&a,&b, &c);
		enqueue(a+1, b, c+1);
		enqueue(a-1, b, c+1);
		enqueue(a, b+1, c+1);
		enqueue(a, b-1, c+1);
	}

	/*
	for (i = 0 ; i < n; i++) {
		for (j = 0 ; j < m; j++) {
			printf("%2d", d[i][j]);
		}
		printf("\n");
	}
	for (i = 0 ; i < n; i++) {
		for (j = 0 ; j < m; j++) {
			printf("%c", w[i][j]);
		}
		printf("\n");
	}
	*/

	// find team

	for (i = 0 ; i < n; i++)  {
		for (j = 0 ; j < m; j++) {
			if (w[i][j] == 'X') {
				tx = i;
				ty = j;
			}
		}
	}

	while (1) {
		k = 0;
		int sa, sb;
		for (i = 0 ; i < 4; i++) {
			int a, b;
			a = tx + dx[i];
			b = ty + dy[i];
			if (d[a][b] != -1 && d[a][b] < d[tx][ty]) {
				k ++;
				sa = a;
				sb = b;
			}
		}
		if (k == 1) {
			tx = sa;
			ty = sb;
		} else {
			break;
		}
	}

	for (i = 0 ; i < n ; i++) {
		for (j = 0 ; j < m; j++) {
			switch (w[i][j]) {
				case '#':
					printf("#");
					break;
				case 'X':
				case 'E':
				case '.':
					if (tx == i && ty == j) {
						printf("*");
						break;
					}

					printf("%c", w[i][j]);
					break;
			}
		}

		printf("\n");
	}

	return 0;
}
