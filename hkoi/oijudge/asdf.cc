#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int w[100][100];

/*void dump(int n) {
	for (int i = 0 ; i < n * 2; i ++ ) {
		for (int j =  0 ; j < n*2 ; j ++ ) {
			if (w[i][j] == 1024*1024) { printf("[xx]") ;} else 
			printf("[%d]", w[i][j]);
		};

		printf("\n");
	};
};*/

int main() {
	int n,m;
	scanf("%d %d\n", &n, &m);
	memset(w,0,sizeof(w));
	for (int i = 0 ; i < 100 ; i++ ) {
		for (int j = 0 ; j < 100 ; j++ ) {
			w[i][j] = 1024*1024;
		};
	};
	for (int i = 0 ; i < m ; i ++ ) {
		int a,b,c;
		scanf("%d %d %d\n", &a, &b, &c);
		a--;b--;
		//w[a][b] = c;
		//w[b][a] = c;
		w[a][b+n] = c;
		w[b][a+n] = c;
		w[b+n][a] = c / 5 * 4;
		w[a+n][b] = c / 5 * 4;
	};

	for (int k = 0 ; k < 2*n ; k++ ) {
	for (int i = 0 ; i < 2*n ; i++ ) {
	for (int j = 0 ; j < 2*n ; j++ ) {
	if (w[i][j] > w[i][k] + w[k][j]) {
		w[i][j] = w[i][k] + w[k][j];
	};
	};
	};
	};
	
	printf( "%d\n", min(w[0][1+n], w[0][1])) ;
	printf( "%d\n",
		min(
			w[0][1+n] + min(w[1+n][0],w[1+n][n]),
			w[0][1] + min(w[1][0] , w[1][n])
		)
	) ;
};

