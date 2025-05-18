#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SIZ 1000

// char map[SIZ][SIZ];

int rowcount[3*SIZ];
int colcount[3*SIZ];
int dia1count[3*SIZ];
int dia2count[3*SIZ];
int n;
int cpos[SIZ];

int conflicts = 0;

int depth = 0;

void dump() {
	return; 
	/*printf("Conflicts: %d\n", conflicts);
	for (int i = 0 ; i < n ; i++ ) {
		for ( int j = 0 ; j < n ; j ++ ) { 
			printf("%d", map[i][j]);
		};
		printf("\n");
	};*/
	//char a;
	//scanf("%c", &a);
};

bool reg(int row, int col) {
	rowcount[row]++;
	colcount[col]++;
	dia1count[row+col]++;
	dia2count[row-col+n]++;
	if (rowcount[row] > 1) conflicts++;
	if (colcount[col] > 1) conflicts++;
	if (dia1count[row+col] > 1) conflicts++;
	if (dia2count[row-col+n] > 1) conflicts++;

	// map[row][col] = 1;
	cpos[row] = col;
	return true;
};

bool rem(int row, int col) {
	if (cpos[row] != col) return false;
	//if (map[row][col] != 1) return false;
	
	if (rowcount[row] > 1) conflicts--;
	if (colcount[col] > 1) conflicts--;
	if (dia1count[row+col] > 1) conflicts--;
	if (dia2count[row-col+n] > 1) conflicts--;
	
	rowcount[row]--;
	colcount[col]--;
	dia1count[row+col]--;
	dia2count[row-col+n]--;
	//map[row][col] = 0;
	cpos[row] = -1;

	return true;
};

int main() {
	//memset(map,0,sizeof(map));


	scanf("%d", &n);

	memset(rowcount,0,sizeof(rowcount));
	memset(colcount,0,sizeof(colcount));
	memset(dia1count,0,sizeof(dia1count));
	memset(dia2count,0,sizeof(dia2count));

	for (int i = 0 ; i <n ; i ++)  {
		reg(i, rand() % n );
	};
	int cnt = 0;

	while (conflicts != 0) {
		// find a conflicting row / dia (no col)
		if (cnt % 1000 == 0 && conflicts <  (int) sqrt(n) ) {
				//printf("Random Restart %d\n", conflicts);
				for (int i = 0; i < n ; i ++ ) {
						rem(i, cpos[i]);
				};
				for (int i = 0 ; i <n ; i ++)  {
					reg(i, rand() % n );
				};
		};
		int better = 0;
		
		int r = rand() % n;
		while (true) {
			if ( colcount[ cpos[r] ] > 1 || dia1count[r+cpos[r]] > 1 || dia2count[r-cpos[r]+n] > 1) {
				// find a new column that has less conflict
				int origconflicts = conflicts;
				int oldcpos = cpos[r];

				rem(r, oldcpos);

				for (int i = 0 ; i < n ; i ++ ) {
					reg(r, i);
					if (conflicts < origconflicts) {
						better = origconflicts - conflicts;
						break;
					};
					rem(r, i);
				};

				if (better == 0) { 
					if (rand() % 7 == 0) {
							reg(r, rand() % n);
					} else {
							reg(r, oldcpos) ;
					};
					cnt ++;
				};
				break;
			};
			r = rand() % n;
		};
	};
	for (int i = 0 ; i < 2*n ; i ++ ) { 
			if (rowcount[i] > 1 || colcount[i] > 1 || dia1count[i] > 1 || dia2count[i] > 1) {
					printf("Fxxked!\n");
					throw(0);
			};
	};

	for (int i = 0 ; i < n ; i++ ) {
			printf("%d %d\n", i+1, cpos[i]+1);
	};
};
