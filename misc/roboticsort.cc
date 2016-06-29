#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>

/*
   ncurses
*/

int w[100];
int N;
int picked = 0;
int pt = 0;
int z = 0;

void init() {
	for (int i = 0 ; i < N; i++) {
		w[i] = i;
	}
	for (int i = 0 ; i < N*N; i++) {
		int a = rand() % N;
		int b = rand() % N;
		int c;

		c = w[a];
		w[a] = w[b];
		w[b] = c;
	}
}

void dump()
{
	move(0,0);
	for (int i = 0 ; i < N; i++) {
		if (i == pt && picked) {
			printw(" %2d ", w[i]+1);
		} else if (i == pt) {
			printw("  v ");
		} else {
			printw("    ");
		}
	}
	printw("\n");

	for (int i = 0 ; i < N; i++) {
		if (i == pt && picked) {
			printw("[..]");
		} else {
			printw("[%2d]", w[i]+1);
		}
	}
	printw("\n");
	printw("\"Score\": %d\n", z);
	printw("LEFT RIGHT: move pointer, ENTER: select number\n");
}

int issorted() {
	for (int i = 0 ; i < N; i++) {
		if (w[i] != i) return 0;
	}
	return 1;
}

int main() {
	WINDOW* win;
	win = initscr();
	keypad(win, 1);
	while (1) {
		z = 0;
		pt = 0;
		int seed;
		echo();
		curs_set(1);
		while (N <= 0 || N > 20) {
			printw("Size of N = ? (input 0 to exit)\n");
			scanw("%d", &N);
			if (N == 0) goto hell;
			printw("Random Seed = ? (input 0 if you dont' want a specific number)\n");
			scanw("%d", &seed);
			if (seed == 0) seed = time(NULL);
			srand(seed);

		}
		curs_set(0);
		clear();
		noecho();
		init();
		while (1) {
			dump();
			int k = getch();
			switch (k) {
				case KEY_LEFT:
					if (pt > 0) {
						z++;
						if (picked) {
							int a = w[pt];
							w[pt] = w[pt-1];
							w[pt-1] = a;
						}
						pt--;
					}
					break;
				case KEY_RIGHT:
					if (pt < N-1) {
						z++;
						if (picked) {
							int a = w[pt];
							w[pt] = w[pt+1];
							w[pt+1] = a;
						}
						pt++;
					}
					break;
				case '\n':
					picked = !picked;
					printw("%d\n", picked);
					z++;
					break;
			}

			if (!picked && issorted()) { 
				dump();
				break;
			}
		}

		printw("\nN = %d, seed = %d, score = %d\n\n\n\n", N, seed, z);
		N = 0;
	}
hell:
	endwin();
}

