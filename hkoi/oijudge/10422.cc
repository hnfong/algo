#include <stdio.h>

char map[5][5];

int emptyx, emptyy;

int x[8] = { +1, +1, +2, +2, -1, -1, -2, -2 };
int y[8] = { +2, -2, +1, -1, -2, +2, -1, +1 };

int level = 0;
int maxl;
int right = 0;

char correctmap[5][5] = {
	{ '1', '1', '1', '1', '1' },
	{ '0', '1', '1', '1', '1' },
	{ '0', '0', ' ', '1', '1' },
	{ '0', '0', '0', '0', '1' },
	{ '0', '0', '0', '0', '0' }
};

int knightdist[5][5] = {
	{ 4, 1, 2 , 1 , 4 },
	{ 1, 2, 3 , 2, 1 },
	{ 2, 3, 0, 3 , 2},
	{ 1, 2, 3 , 2, 1 },
	{ 4, 1, 2 , 1 , 4 }
};

void dump( ) {
	return;
	printf("Level %d, Correct %d\n", level, right);
	for (int i = 0 ;i < 5; i++ ) {
		for (int j = 0 ; j < 5; j++ ) {
			printf("[%c]", map[i][j]);
		};
		printf("\n");
	}; printf("\n");
};

bool found = false;

int ans[30][2];
int ansk = 0;

void ids() {
	if (right == 25) {
		found = true;
		//dump();
		return;
	};
	if (level + (25-right-1) > maxl) return;
	level ++;

	// check objects that have been put in the wrong position

	//dump();

	for (int i = 0; i < 8 ; i ++ ) {
		if (emptyx+x[i] >= 0 && emptyx+x[i] < 5 && emptyy+y[i] >= 0 && emptyy+y[i] < 5) {
			int cor = 0;
			
			// original correctness
			if ((map[emptyx + x[i]][emptyy + y[i]] ^ correctmap[emptyx + x[i]][emptyy + y[i]]) == 0) cor--;
			if ((map[emptyx][emptyy] ^ correctmap[emptyx][emptyy]) == 0) cor--;
			
			char c = map[emptyx + x[i]][emptyy + y[i]];
			map[emptyx][emptyy] = map[emptyx + x[i]][emptyy + y[i]];
			emptyx += x[i];
			emptyy += y[i];
			map[emptyx][emptyy] = ' ';

			// new correctness
			if ((map[emptyx - x[i]][emptyy - y[i]] ^ correctmap[emptyx - x[i]][emptyy - y[i]]) == 0) cor++;
			if ((map[emptyx][emptyy] ^ correctmap[emptyx][emptyy]) == 0) cor++;

			right += cor;

			ids();

			right -= cor;
			map[emptyx][emptyy] = c;
			emptyx -= x[i];
			emptyy -= y[i];
			map[emptyx][emptyy] = ' ';
			if (found) {
				//printf("%d %d\n", emptyx+x[i]+1, emptyy+y[i]+1);
				ans[ansk][0] = emptyx+x[i]+1;
				ans[ansk][1] = emptyy+y[i]+1;
				ansk++;
				break;
			};
		};
	};

	level --;
};

int main() {
	int n;
	scanf("%d\n", &n);
	while (n > 0) {
		level = 0;
		right = 0;

		for (int i = 0 ; i < 5 ; i ++ ){
			for (int j = 0 ; j < 5 ; j ++ ) {
				map[i][j] = getc(stdin);
				if (map[i][j] == ' ') {
					emptyx = i;
					emptyy = j;
				};
				if ( (map[i][j] ^ correctmap[i][j]) == 0 ) {
					right++;
				};
			};
			fgetc(stdin);
		};

		//printf("%d %d", right, level);

		for (maxl = 1; maxl <= 10; maxl ++ ) {
			//printf("---- %d ----\n", maxl);
			ids();
			if (found) break;
		};

		if (!found) {
			printf("Unsolvable in less than 11 move(s).\n");
		} else {
			printf("Solvable in %d move(s).\n", ansk);
		};

		while (ansk > 0) {
			ansk--;
			//printf("%d %d\n", ans[ansk][0], ans[ansk][1]);
		};
		n--;
		found = false;
	};
};

