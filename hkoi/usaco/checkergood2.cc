#include <stdio.h>
#include <string.h>

int u[20];

int w[20][20];

int level = 0;
int n;
int answers = 0;

void dump() {
	printf("level %d\n", level);
	for (int i = 0 ; i < n ; i++ ) {
		for (int j = 0 ; j < n ; j++ ) {
			printf("%d ", w[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int cnt = 0;
void ex(int col) {
	cnt++;
	for (int i = 0; i < n-level; i++) { w[level+i][col]++; }
	for (int i = 0; i < n-level; i++) { if (col+i >= n) break; w[level+i][col+i]++; }
	for (int i = 0; i < n-level; i++) { if (col-i < 0) break; w[level+i][col-i]++; }
	//dump();
	u[level] = col;
	if (level == n-1) {
		if (answers++ < 3) {
			for (int i = 0; i < n; i++ ) {
				printf("%s", (i==0)?"":" ");
				printf("%d", u[i]+1);
			}printf("\n");
		}
		goto hell;
	}
	level ++;
	for (int i = 0 ; i < n; i++ ) {
		if (w[level][i] == 0) ex(i);
	}


	level --;
hell:
	for (int i = 0; i < n-level; i++) { w[level+i][col]--; }
	for (int i = 0; i < n-level; i++) { if (col+i >= n) break; w[level+i][col+i]--; }
	for (int i = 0; i < n-level; i++) { if (col-i < 0) break; w[level+i][col-i]--; }
}


int main() {
	memset(w,0,sizeof(w));
	scanf("%d", &n);
	for (int i = 0 ; i < n; i++) ex(i);
	printf("%d\n", answers);
	printf("%d\n", cnt);
}
