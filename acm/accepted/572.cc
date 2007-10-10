#include <stdio.h>
#include <string.h>


char w[101][101];
bool u[101][101];
int m,n;

void search(int r,int c) {
	if (r < 0 || r >= m) return;
	if (c < 0 || c >= n) return;
	if (u[r][c]) return;
	if (w[r][c] == '*') return;

	u[r][c] = 1;

	search(r+1, c+1);
	search(r+0, c+1);
	search(r-1, c+1);
	
	search(r+1, c+0);
	// search(r+0, c+0);
	search(r-1, c+0);

	search(r+1, c-1);
	search(r+0, c-1);
	search(r-1, c-1);
}
int main() {
	while (scanf("%d %d\n", &m, &n), m)
	{
		memset(w,0,sizeof(w));
		memset(u,0,sizeof(u));

		for (int i = 0 ; i < m ; i ++)
		{
			gets(w[i]);
		}

		int z = 0;
		for (int i = 0 ; i < m; i++)
		{
			for (int j = 0 ; j < n; j++)
			{
				if (w[i][j] == '@' && !u[i][j]) {
					search(i,j);
					z++;
				}
			}
		}

		printf("%d\n", z);
	}
}
