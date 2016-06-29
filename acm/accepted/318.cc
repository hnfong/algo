#include <stdio.h>
#include <stdlib.h>


#define BIG 1000000000
int max(int a, int b) {
	return (a > b ? a : b);
}

int main(){
	int cse = 0;
	int n,m;
	while (scanf("%d %d", &n, &m), n) {
		int w[n][n];
		int v[n][n];
		for (int i = 0; i < n; i++ )
		for (int j = 0; j < n; j++ )
		{
			w[i][j] = BIG;
			v[i][j] = BIG;
			w[i][i] = 0;
		}
			
		for (int i = 0 ; i < m; i++) {
			int a,b,c;
			scanf("%d %d %d", &a,&b,&c);
			a--;b--;
			w[a][b] = c;
			w[b][a] = c;

			v[a][b] = c;
			v[b][a] = c;
		}

		for (int k = 0; k < n; k++ )
		for (int i = 0; i < n; i++ )
		for (int j = 0; j < n; j++ )
			if (w[i][j] > w[i][k] + w[k][j])
				w[i][j] = w[i][k]+w[k][j];

		int best = 0, besta = 0, bestb = -1;

		for (int i = 0 ; i < n; i++) {
			if (best < w[0][i] *2 ) {
				best = w[0][i] *2 ;
				besta = i;
				bestb = -1;
			}
		}

		for (int i = 0 ; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] != BIG && w[0][i]+v[i][j] > w[0][j]) {
					int d = max(w[0][i],w[0][j]) * 2 + v[i][j] - abs(w[0][i]-w[0][j]);
					if (best < d) {
						best = d;
						besta = i;
						bestb = j;
					};

				}
			}
		}

		printf("System #%d\n", ++cse);
		if (bestb  == -1) {
			printf("The last domino falls after %.1f seconds, at key domino %d.\n", best/2.0, besta + 1);
		} else {
			printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n", best/2.0, besta + 1, bestb + 1);
		}
		printf("\n");
	}
}
