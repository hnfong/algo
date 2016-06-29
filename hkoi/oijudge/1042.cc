#include <stdio.h>
#include <string.h>

const int x[8] = { +1, +1, +2, +2, -1, -1, -2, -2 };
const int y[8] = { +2, -2, +1, -1, -2, +2, -1, +1 };

char map[5][5];
char origmap[5][5];
char intermap[5][5];


int emptyx, emptyy;
int mode = 0;


int level = 0;
int maxl;

bool found = false;
bool intersect = false;

int ans[30][2];
int ansk = 0;

char correctmap[5][5] = {
	{ '1', '1', '1', '1', '1' },
	{ '0', '1', '1', '1', '1' },
	{ '0', '0', 'x', '1', '1' },
	{ '0', '0', '0', '0', '1' },
	{ '0', '0', '0', '0', '0' }
};

char ht[1000001][25];
char hb[1000001];
char htemp[1000001];

//#define DEBUG

#ifdef DEBUG
#define dprintf printf
#else
#define dprintf(...)
#endif

void dump( char *m ) {
	return;
	dprintf("Level %d\n", level);
	for (int i = 0 ;i < 5; i++ ) {
		for (int j = 0 ; j < 5; j++ ) {
			dprintf("[%c]", m[i*5+j]);
		};
		dprintf("\n");
	}; dprintf("\n");
};

int hashval() {
	unsigned long long t = 0;
	for (int i = 0 ; i <  5; i ++ ) {
		for (int j = 0 ; j < 5 ; j ++ ) {
			t += map[i][j] * (1 << (i*5+j));
		};
	};
	return (t % 1000001);
};

int hash(char who) {
	int hv = hashval();

	while (ht[hv][0] != 0) {
		// collision
		if (memcmp(ht[hv], map, 25) == 0) {
			// already hashed
			return hb[hv];
		};
		hv++;
	};
	// empty
	memcpy(ht[hv], map, 25);
	hb[hv] = who;
	htemp[hv] = level;
	return who;
};

int computeright() {
	int k = 0;
	for (int i = 0 ; i < 5 ; i++ ) {
		for (int j = 0 ; j < 5 ; j ++ ) {
			if ((map[i][j] ^ correctmap[i][j]) == 0) {
				k++;
			};
		};
	};
	return k;
};



void ids() {
	int right2 = computeright();
	if (right2 == 24){
		found = true;
		dprintf("We found you\n");
		return;
	};

	//dump( (char *) map);
	dprintf("[right %d wrong %d max %d]\n", right2, level + (24 - right2), maxl);
	if (level + (24 - right2) > maxl) return;
	// if (level > maxl) return;

	if (mode == 2) {
		if (memcmp(map, intermap, 25) == 0) {
			found = true;
			return;
		};
	} else {
		if (hash(mode) != mode) {
			dprintf("found level %d %d\n", level, htemp[hashval()]);
			dump((char *) map);
			found = true;
			memcpy(intermap, map, 25);
			intersect = true;
			return;
		};
	};

	level ++;

	// check objects that have been put in the wrong position

	for (int i = 0; i < 8 ; i ++ ) {
		if (emptyx+x[i] >= 0 && emptyx+x[i] < 5 && emptyy+y[i] >= 0 && emptyy+y[i] < 5) {
			char c = map[emptyx + x[i]][emptyy + y[i]];
			map[emptyx][emptyy] = map[emptyx + x[i]][emptyy + y[i]];
			emptyx += x[i];
			emptyy += y[i];
			map[emptyx][emptyy] = ' ';

			ids();

			map[emptyx][emptyy] = c;
			emptyx -= x[i];
			emptyy -= y[i];
			map[emptyx][emptyy] = ' ';
			if (found) {
				//dprintf("%d %d\n", emptyx+x[i]+1, emptyy+y[i]+1);
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
	int emptyx_save, emptyy_save;
	char map_save[5][5];
	char correctmap_save[5][5];
	
	memset(ht,0,sizeof(ht));
	memset(hb,0,sizeof(hb));
	for (int i = 0 ; i < 5 ; i ++ ){
		for (int j = 0 ; j < 5 ; j ++ ) {
			map[i][j] = getc(stdin);
			if (map[i][j] == ' ') {
				emptyx = i;
				emptyy = j;
			};
		};
		fgetc(stdin);
	};

	memcpy(map_save, map, 25);
	memcpy(correctmap_save, correctmap, 25);
	emptyx_save = emptyx;
	emptyy_save = emptyy;

	for (maxl = 1; maxl <= 20; maxl++) {
		mode = 0;
		memcpy(map, map_save, 25);
		memcpy(correctmap, correctmap_save, 25);
		emptyx = emptyx_save;
		emptyy = emptyy_save;
		map[emptyx][emptyy] = ' ';
		ansk = 0;
		
		dprintf("[---- %d ----]\n", maxl);
		ids();
		
		if (found) {
			dprintf("Found lu~\n");
			if (!intersect) {
				while (ansk > 0) {
					ansk--;
					printf("%d %d\n", ans[ansk][0], ans[ansk][1]);
				};
			};
			break;
		};

		mode = 1;
		memcpy(map, correctmap_save, 25);
		memcpy(correctmap, map_save, 25);
		emptyx = 2;
		emptyy = 2;
		map[emptyx][emptyy] = ' ';
		correctmap[emptyx_save][emptyy_save] = 'x';
		ansk = 0;
		dprintf("(---- %d ----)\n", maxl);
		ids();

		if (found) {
			dprintf("Found lu~\n");
			if (!intersect) {
				while (ansk > 0) {
					ansk--;
					printf("%d %d\n", ans[ansk][0], ans[ansk][1]);
				};
			};
			break;
		};
	};

	if (intersect) {
		found = false;
		dprintf("Finding intersect point again\n");

		for (maxl = 1; maxl < 20 ; maxl ++ ) {
			dprintf("(---- %d ----)\n", maxl);
			mode = 2;
			memcpy(map, map_save, 25);
			memcpy(correctmap, intermap, 25);
			emptyx = emptyx_save;
			emptyy = emptyy_save;
			map[emptyx][emptyy] = ' ';
			ansk = 0;
			ids();

			if (found) {
				while (ansk > 0) {
					ansk--;
					printf("%d %d\n", ans[ansk][0], ans[ansk][1]);
				};
				break;
			};
		};

		for (maxl = 1; maxl < 20; maxl ++ ) {
			found = false;
			dprintf("(---- %d ----)\n", maxl);
			mode = 2;
			memcpy(map, correctmap_save, 25);
			memcpy(correctmap, intermap, 25);
			for (int i = 0 ; i < 5; i++ ) {
				for (int j = 0 ; j < 5 ;j ++ ) {
					if (correctmap[i][j] == ' ') { correctmap[i][j] = 'x'; };
				};
			};
			ansk = 0;
			emptyx = 2;
			emptyy = 2;
			map[2][2] = ' ';
			ids();
			if (found) {
				for (int i = 1 ; i < ansk; i++ ) {
					printf("%d %d\n", ans[i][0], ans[i][1]);
				};
				break;
			};
		};

		printf("3 3\n");
	};
};

