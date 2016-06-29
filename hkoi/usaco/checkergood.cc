#include <stdio.h>

int u[20];

int level = -1;
int n;
int answers = 0;

void ex(int col) {
	level ++;
	
	for (int i = 0 ;  i < level ; i++ ) {
		if (u[i] == col || u[i]-i == col-level || u[i]+i == col+level ) { level -- ; return; }
	}
	
	u[level] = col;
	if (level == n-1) {
		/*
			for (int i = 0; i < n; i++ ) {
				printf("%s", (i==0)?"":" ");
				printf("%d", u[i]+1);
			}printf("\n");
			*/
		answers++;
		level --;
		return;
	}
	for (int i = 0 ; i < n; i++ ) {
		ex(i);
	}

	level --;
}


int main() {
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i++ ) {
		ex(i);
	}
	printf("%d\n", answers);
}
