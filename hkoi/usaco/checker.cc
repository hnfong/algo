#include <stdio.h>

int u[20];

int n;
int answers = 0;
int mid;
int nex[20];
int lev[20];
int cnt = 0;

int level(int k) {
	return k;
	if (k > mid) {
		return (n-k)*2-1;
	} else {
		return k*2;
	}
}

int next(int k) {
	return k+1;
	int l;
	l=level(k);

	l++;

	if (l % 2 == 0) {
		return l/2;
	} else {
		return n-(l+1)/2;
	}
}

void ex(int row, int col) {
	// printf("%d %d\n", row, col);
	int k = 0;
	for (int i = 0;  i < lev[row]; i++ ) {
		if (u[k] == col || u[k]-k == col-row || u[k]+k == col+row ) { return; }
		k = nex[k];
	}
	cnt ++;
	
	u[row] = col;
	
	if (row == n-1) {
		if (answers < 3) {
			for (int i = 0; i < n; i++ ) {
				printf("%s", (i==0)?"":" ");
				printf("%d", u[i]+1);
			}printf("\n");
		}
		answers++;
	} else {
		for (int i = 0 ; i < n; i++ ) {
			ex(nex[row], i);
		}
	}

	u[row] = -1;
}


int main() {
	scanf("%d", &n);
	mid = (n-1)/2;
	for (int i = 0 ; i < n ; i++ ) {
		u[i] = -1;
		nex[i] = next(i);
		lev[i] = level(i);
		printf("%d %d %d\n", i, nex[i], lev[i]);
	}
	for (int i = 0 ; i < n ; i++ ) {
		ex(0,i);
	}
	
	printf("%d\n", answers);
	printf("%d\n", cnt);
}

