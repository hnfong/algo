#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

#define SIZ 5

char moves[2][8] = {
	{ 1,  1, -1, -1, 2,  2, -2, -2 },
	{ 2, -2,  2, -2, 1, -1,  1, -1 }
};
char correctmap[5][5] = {
	{'1','1','1','1','1'},
	{'0','1','1','1','1'},
	{'0','0',' ','1','1'},
	{'0','0','0','0','1'},
	{'0','0','0','0','0'}
};

char minmoves[5][5] = {
	{0,3,2,3,2},
	{3,2,1,2,3},
	{2,1,4,3,2},
	{3,2,3,2,3},
	{2,3,2,3,4}
};

char map[5][5];

int level = 0;
int best;

int ei,ej;

stack<int> ansi;
stack<int> ansj;

void dump() {
	return;
	printf("Level %d Max %d\n", level, best);
	for (int i = 0 ; i< SIZ ; i++ ) {
		for (int j = 0 ; j < SIZ ; j ++ ) {
			printf("%c", map[i][j]);
		};
		printf("\n");
	}; printf("\n");
};

int find_nearest_opp_color(int a, int b) {
	int e = 9999;
	for (int i = 0 ; i < SIZ; i++)  {
		for (int j = 0 ; j < SIZ; j++ ) {
			if (minmoves[abs(i-a)][abs(j-b)] < e && map[i][j] != map[a][b] && correctmap[i][j] == map[a][b]) {
				e = minmoves[abs(i-a)][abs(j-b)];
				if (e == 1) return e;
			};
		};
	};
	return e;
};

int heuristic() {
	int k1 = 0;
	for (int i = 0 ; i < SIZ; i++ ){
		for (int j = 0 ; j < SIZ; j++ ) {
			if (map[i][j] == correctmap[i][j] || map[i][j] == ' ') continue;
			k1 += find_nearest_opp_color(i,j);
			//printf("%d %d %d\n", i,j, find_nearest_opp_color(i,j));
		};
	};
	return (k1);
};

int ida() {
	if (memcmp(correctmap, map, 25) == 0) { return true; };
	if (level + heuristic()  > best) return false;

	for (int m = 0 ; m < 8 ; m++ ) {
		if (ei+moves[0][m] >= SIZ) continue;
		if (ej+moves[1][m] >= SIZ) continue;
		
		if (ei+moves[0][m] < 0) continue;
		if (ej+moves[1][m] < 0) continue;
		swap(map[ei][ej], map[ei+moves[0][m]][ej+moves[1][m]]);
		
		ei += moves[0][m];
		ej += moves[1][m];
		level ++;

		bool b = ida();
		if (b) { 
			ansi.push(ei+1);
			ansj.push(ej+1);
		};

		level --;
		ei -= moves[0][m];
		ej -= moves[1][m];
		swap(map[ei][ej], map[ei+moves[0][m]][ej+moves[1][m]]);

		if (b) return true;
	};
	return false;
};


int main() {
	memset(map,0,sizeof(map));
	for (int i = 0 ; i< SIZ ; i++ ) {
		for (int j = 0 ; j < SIZ ; j ++ ) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == ' ') {
				ei = i;
				ej = j;
			};
		};
		getc(stdin);
	};

	printf("H: %d\n", heuristic());

	for (best = 0 ; best <= 20 ; best ++ ) {
		if (ida()) break;
	};

	printf("Best %d\n", best);

	while (!ansi.empty()) {
		printf("%d %d\n", ansi.top(), ansj.top());
		ansi.pop();
		ansj.pop();
	};
};

