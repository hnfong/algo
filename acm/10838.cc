#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <map>

using namespace std;

const int pow3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};

// #define DEBUG
void dump(char w[4][4]) {
#ifdef DEBUG
	for (int i = 0 ; i < 4 ; i ++ ) {
		for (int j = 0 ; j < 4; j++ ) {
			printf("%c", w[i][j]);
		}
		printf("\n");
	}
#endif
}

void debug(char *s, int line) {
#ifdef DEBUG
	printf("%s @ %d\n", s, line);
#endif
}

void debug(char *s) {
#ifdef DEBUG
	printf("%s\n", s);
#endif
}

void debug(int k) {
#ifdef DEBUG
	printf("%d\n", k);
#endif
}

int p2d(char c) {
	switch(c) {
		case '.': return 0;
		case 'p': return 1;
		case 'P': return 2;
	}
	debug("wrong @ p2d");
	throw(1);
}

char d2p(int k ) {
	switch(k) {
		case 0: return '.';
		case 1: return 'p';
		case 2: return 'P';
	}
	debug("wrong ", __LINE__);
	throw(2);
}

int hash(char w[4][4]) {
	int z = 0;
	int k = 0;
	for (int i = 0; i < 4 ; i ++ ) {
		for (int j = 0; j < 4; j++) {
			z += p2d(w[i][j])*pow3[k];
			k++;
		}
	}
	return z;
}

void unhash(int hash, char w[4][4]) {
	memset(w,0,sizeof(w));
	for (int i = 0 ; i < 16; i++) {
		int k = hash % 3;
		w[i/4][i%4] = d2p(k);
		hash/=3;
	}
}

// char v[43046721][2];
map<int, char> v[2];

int prefer(int a, int b) {
	if (b > 0) b++;
	if (b < 0) b--;
	
	// we want to win!
	if (a > 0 && b < 0) return a;
	if (a < 0 && b > 0) return b;

	// we want to win a soon as possible
	if (a > 0 && b >0) {
		if (a > b) return b; else return a;
	}

	// we wnat to lose as late as possible
	if (a < 0 && b < 0) {
		if (a > b) return b; else return a;
	}

	throw(3);
}

char findmax(int state, int player) {
	if (v[player][state] != 0) {
		return v[player][state];
	}

	char w[4][4];
	char w2[4][4];
	unhash(state,w);

	debug("called findmax", player);
	dump(w);

	int best = -1;
	int dforward;
	int firstrank;
	int otherplayer;
	char othercolor;
	char thiscolor;
	
	switch (player) {
		case 0:
			dforward = -1;
			firstrank = 3;
			othercolor = 'p';
			otherplayer = 1;
			thiscolor = 'P';
			break;
		case 1:
			dforward = +1;
			firstrank = 0;
			othercolor = 'P';
			otherplayer = 0;
			thiscolor = 'p';
			break;
	}
	
	// if somebody invades our first rank, we lose!, cant do anything!
	for (int i = 0 ; i < 4; i++) {
		for (int j = 0 ; j < 4; j ++)  {
			if (w[i][j] == othercolor && i == firstrank) {
				best = -1;
				goto hell;
				continue;
			}
		}
	}
	
	for (int i = 0 ; i < 4; i++) {
		for (int j = 0 ; j < 4; j ++)  {
			if (w[i][j] == thiscolor) {
				// try move forward
				memcpy(w2,w,16);
				if (w[i+dforward][j] == '.') {
					w2[i][j] = '.';
					w2[i+dforward][j] = thiscolor; 
					debug("");
					debug("from:");
					dump(w);
					best = prefer(best, -findmax(hash(w2), otherplayer));
				}

				// try eating left
				memcpy(w2,w,16);
				if (j > 0 && w[i+dforward][j-1] == othercolor) {
					w2[i][j] = '.';
					w2[i+dforward][j-1] = thiscolor; 
					debug("from:");
					dump(w);
					best = prefer(best, -findmax(hash(w2), otherplayer));
				}

				// try eating right
				memcpy(w2,w,16);
				if (j < 3 && w[i+dforward][j+1] == othercolor) {
					w2[i][j] = '.';
					w2[i+dforward][j+1] = thiscolor; 
					debug("from:");
					dump(w);
					best = prefer(best, -findmax(hash(w2), otherplayer));
				}
			}
		}
	}

hell:
#ifdef DEBUG
	printf("******** conclusion *******\n");
	dump(w);
	printf("findmax(%d, %d) == %d\n", state, player, best);
	printf("i.e. (%s to move) white %s and black %s in %d steps\n", (player == 0 ? "white": "black"), (!(best > 0) xor (player==0))?"win":"lose", ((best > 0) xor (player==0))?"win":"lose", (best> 0? best: -best)-1 );
#endif
	v[player][state] = best;
	return best;
}

int main(){
	int n;
	scanf("%d\n\n", &n);
	char win[4][4];
	while (n--) {
		v[0].clear();
		v[1].clear();
		// memset(v, 0, sizeof(v));

		debug("**********beginning of new case************");
		char s[100];
		for (int i = 0 ; i < 4; i++) {
			fgets(s, 50, stdin);
			win[i][0] = s[0];
			win[i][1] = s[1];
			win[i][2] = s[2];
			win[i][3] = s[3];
		}
		fgets(s, 50, stdin);

		dump(win);
		int ans = findmax( hash(win), 0 );

		if (ans < 0) {
			printf("black (%d)\n", (-ans)-1);
		} else {
			printf("white (%d)\n", ans-1);
		}
	}
}
