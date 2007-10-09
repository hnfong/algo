#include <stdio.h>
#include <queue>

#define push(a,b,c) { u[(a)][(b)][(c)] = true; q.push(nod((a),(b),(c))); }

using namespace std;

int w[1100][1100];
char map[600][600];
int t;
struct nod {
	nod (int r,int c, int o) { // 0 = Top, 1 = Bottom
		this->r = r;
		this->c = c;
		this->o = o;
	}
	int r,c,o;
};

int dr[] = {1,0,-1,0};
int dc[] = {0,-1,0,1};

int arrival[2][4] = { // '/', '\' |||| down, left, up, right, 
	{0,1,1,0,},
	{1,1,0,0,},
};

int departure[2][2][2] = {
	// '/'
	{ {1,2}, {0,3}, }, // left, right
	// '\'
	{ {0,1}, {2,3}, }, // left, right
};

queue<nod> q;

bool u [500][500][2];

int main() {
	int n,m;
	scanf("%d", &t);
	while (t--)
	{
		int res = 0;
		memset(u,0,sizeof(u));

		scanf("%d %d\n", &n,&m);
		for (int i = 0 ; i < m; i++)
		{
			gets(map[i]);
		}

		for (int k = 0 ; k < n - 1; k++)
		{
			if (map[0][k] == map[0][k+1]) {
				push(0,k,1);
			}
		}

		while (q.size() != 0)
		{
			nod k = q.front();
			q.pop();
			// printf("[%d,%d]\n", k.r, k.c);
			for (int i = 0 ; i < 2;i ++)
			{
				int z = 0;
				if (map[k.r][k.c] != '/') z = 1;
				int d = departure[z][k.o][i];
				
				int r = k.r + dr[d];
				int c = k.c + dc[d];

				// printf("{%d,%d}", r,c);

				if (r == m) { res ++; continue; }
				if (r < 0) { continue; }
				if (c < 0) { continue; }
				if (c >= n) { continue;}

				z = 0;
				if (map[r][c] != '/') z = 1;
				int o = arrival[z][d];

				if (u[r][c][o]) { continue; }
				push(r,c,o);

			}
		}
		printf("%d\n", res);
	}
}
