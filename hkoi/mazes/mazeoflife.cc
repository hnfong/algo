#include <stdio.h>
#include <string.h>

#define MAX_SIZ 10

int map[MAX_SIZ][MAX_SIZ];

int dir[9][2] = {
	{-1,-1}, {-1,0}, {-1,1},
	{0,-1}, {0,1}, {1,-1},
	{1,0}, {1,1}, {0,0}
};

int n,m;
int enda,endb;
//int mypos_i,mypos_j;
int si[1000];
int sj[1000];
int sp = -1;

int init_algo() {
	for (int i = 0 ; i < MAX_SIZ; i ++ ) { for (int j = 0 ; j < MAX_SIZ; j ++ ) { map[i][j] = '.'; }; };
	FILE *fp;
	fp = fopen("mazeoflife.txt", "r");
	if (fp == NULL) { return -1; };
	fscanf(fp,"%d", &n);
	fscanf(fp, "%d", &m);
	fgetc(fp); //eat the line;
	for (int i = 0; i < n ; i++ ) {
		for (int j = 0 ; j < m ; j ++)  {
			map[i][j] = fgetc(fp);
			if (map[i][j] == '!') {
				// treat the end point as empty spot
				map[i][j] = '.';
				enda = i;
				endb = j;
			};
			if (map[i][j] == 'X') {
				sp++;
				si[sp]=i;
				sj[sp]=j;
			};
		};

		fgetc(fp); // eat the line;
	};
	fclose(fp);
	return 0;
};

void sim() {
	int w[MAX_SIZ][MAX_SIZ];
	for (int i = 0; i < n ; i ++ ) {
		for (int j = 0 ; j < m ; j ++ )  {
			w[i][j] = '.';
			int mine = 0;
			int theirs = 0;
			for (int d = 0 ; d < 8; d++ ) {
				int x = i+dir[d][0];
				int y = j+dir[d][1];
				if ( x >= 0 && x < n && y >= 0 && y < m ) {
					if (map[x][y] == 'X') { mine++ ; };
					if (map[x][y] == '@') { theirs++ ; };
				};
			};
			switch (map[i][j]) {
				case '.':
					if (mine+theirs == 3) {
						if (mine > theirs) {
							throw(0);
							w[i][j] = 'X';
						} else {
							w[i][j] = '@';
						};
					};
					break;
				default:
					// have stuff
					if (mine+theirs != 3 && mine+theirs != 2) {
						w[i][j] = '.';
					} else {
						w[i][j] = map[i][j];
					};
					break;
			};
		};
	};
	memcpy(map,w,sizeof(w));
};


bool push_move(int new_i, int new_j) {
	if (map[new_i][new_j] != '.' && map[new_i][new_j] != 'X') return false;
	int z = 0;
	for (int d = 0 ; d < 8; d++ ) {
		int x = new_i+dir[d][0];
		int y = new_j+dir[d][1];
		if ( x >= 0 && x < MAX_SIZ && y >= 0 && y < MAX_SIZ ) {
			if (map[x][y] == '@') { z++ ; };
		};
	};
	if (z!= 2 && z!= 3) { return false; };

	map[si[sp]][sj[sp]] = '.';
	sp ++;
	si[sp] = new_i;
	sj[sp] = new_j;
	map[si[sp]][sj[sp]] = 'X';
	return true;
};

bool pop_move() {
	map[si[sp]][sj[sp]] = '.';
	sp--;
	map[si[sp]][sj[sp]] = 'X';
	return true;
};

int depth = 0;
int limit = 0;

int search(int loc_i, int loc_j) {
	// check if the new location is sane
	if (! (loc_i >= 0 && loc_i < n && loc_j >= 0 && loc_j < m)) { return -1; };

	// store the stuff temporarily
	int w[MAX_SIZ][MAX_SIZ];
	memcpy(w, map, sizeof(map));

	// if can't move then forget it
	if (! push_move(loc_i,loc_j) ) { return -1 ; };

	// if this is the move then great!
	if (loc_i == enda && loc_j == endb) { return 1; };
	depth ++;

	if (depth < limit) {
		sim();
		for (int i = 0 ; i < 9 ; i++ ) {
			if ( search(loc_i + dir[i][0], loc_j + dir[i][1]) == 1) {
				return 1;
			};
		};
	};

	depth--;
	pop_move();
	memcpy(map, w, sizeof(map));
	return 0;
};

int main() {
	if (init_algo() == -1) { 
		printf("Error detected.");
	};

	bool found = false;
	for (limit = 1 ; limit < 1000; limit ++ ) {
		for (int i = 0 ; i < 9 ; i++ ) {
			if (search(si[sp] + dir[i][0], sj[sp] + dir[i][1]) == 1) { found = true; break; };
		};
		if (found) break;
	};

	if (not found) {
		printf("No moves < 100...\n");
	} else 
		for (int i = 0 ; i <= sp; i++ ) {
			printf("%d %d\n", si[i]+1, sj[i]+1);
		};
	return 0;
};

