#include <stdio.h>
#include <string.h>

struct nod {
	int x,y,z,cnt;
};

struct nod q[30*30*30];
bool u[30][30][30];

char map[32][32][32];

int qh,qt;

int dl[] = { 0, 0, 0, 0,-1, 1,};
int dr[] = { 0, 0,-1, 1, 0, 0,};
int dc[] = {-1, 1, 0, 0, 0, 0, };

int main() {
	int l,r,c;
	char useless[10];
	int found;

	while (true) {
		qt = qh = 0;
		found = 0;

		memset(u,0,sizeof(u));
		memset(q,0,sizeof(q));

		scanf("%d %d %d\n", &l, &r, &c);
		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 0 ; i < l ; i ++ ) {
			for (int j = 0; j < r; j ++ ) {
				gets(map[i][j]);
			}
			gets(useless);
		}

		// find S, push

		for (int i = 0; i < l; i ++) {
		for (int j = 0; j < r; j ++) {
		for (int k = 0; k < c; k ++) {
			if (map[i][j][k] == 'S') {
				q[qt].x = i;
				q[qt].y = j;
				q[qt].z = k;
				q[qt].cnt = 0;
				qt ++;
				u[i][j][k] = true;
			}
		} } }

		while (qh != qt) {
			nod a,b;
			a = q[qh];
			qh++;
			for (int i = 0 ; i < 6; i++) {
				b.x = a.x + dl[i];
				b.y = a.y + dr[i];
				b.z = a.z + dc[i];
				b.cnt = a.cnt+1;

				if (b.x < 0 || b.x >= l) continue;
				if (b.y < 0 || b.y >= r) continue;
				if (b.z < 0 || b.z >= c) continue;
				if (u[b.x][b.y][b.z]) continue;

				if (map[b.x][b.y][b.z] == '#') continue;
				if (map[b.x][b.y][b.z] == 'E') found = b.cnt;


				q[qt] = b;
				qt++;

				u[b.x][b.y][b.z] = true;
			}
		}

		if (found) {
			printf("Escaped in %d minute(s).\n", found);
		} else {
			printf("Trapped!\n");
		}
	}
}
