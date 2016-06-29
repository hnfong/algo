#include <stdio.h>
#include <string.h>
#define DEBUG

// m regions, n nodes, l club members
int n,m ,l;
int club[30];

int w[300][300]; // edge
int v[300][300]; // node

#define INFINITY 999999

int main() {
	for (int i = 0 ; i<  300;i ++)
		for (int j = 0 ; j < 300; j++) {
			w[i][j] = INFINITY;
			v[i][j] = INFINITY;
		};
	scanf("%d", &m);
	scanf("%d", &n);
	scanf("%d", &l);
	for (int i = 0 ; i < l; i ++ ) {
		scanf("%d", &club[i]);
	};

	for (int i = 0 ; i < m ; i++ ) {
		int k;
		int t[260];
		scanf("%d\n", &k);
		
		for (int j = 0 ; j < k ; j ++ ) {
			scanf("%d", &t[j]);
			for (int c = 0; c < l; c++ ) {
				if (club[c] == t[j]) {
					v[m+c][i] = 0;
				};
			};
		};

		for (int j = 0; j < k; j++ ) {
			if (w[t[j]][ t[(j+1) % k] ] != INFINITY) {
				v[i][  (int) w[ t[j] ][ t[(j+1) % k ]] ] = 1;
				v[  (int) w[ t[j] ][ t[(j+1) % k ]] ][i] = 1;
			} else {
				w[ t[(j+1)%k] ][ t[j] ] = i;
			};
		};
	};
	
	/*printf("   ");
	for (int j = 0 ; j < m+l ; j ++ ) {
		printf(" %.2d  ", j);
	}; printf("\n");
	for (int i = 0 ; i < m+l ; i++ ) {
		printf("%d: ", i);
		for (int j = 0 ; j < m+l ; j ++ ) {
			if (v[i][j] != INFINITY) {
				printf("[ %d] ", v[i][j]);
			} else {
				printf("[  ] ", v[i][j]);
			};
		};

		printf("\n");
	};*/

	for (int k = 0 ; k < m+l ; k++ ) {
		for (int i = 0; i < m+l; i ++ ) {
			for (int j = 0 ; j  < m+l ; j ++ ) {
				if (v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
				};
			};
		};
	};
	 
	/*printf("   ");
	for (int j = 0 ; j < m+l ; j ++ ) {
		printf(" %.2d  ", j);
	}; printf("\n");
	for (int i = 0 ; i < m+l ; i++ ) {
		printf("%d: ", i);
		for (int j = 0 ; j < m+l ; j ++ ) {
			if (v[i][j] != INFINITY ) {
				printf("[ %d] ", v[i][j]);
			} else {
				printf("[  ] ", v[i][j]);
			};
		};

		printf("\n");
	};*/

	int e = INFINITY;

	for (int i = 0; i < m; i++ ) {
		int z = 0;
		for (int j = m; j < m+l ;j ++ ) {
			z += v[j][i];
		};
		if (z < e) { e = z ; };
	};

	printf("%d\n", e);
	
};
