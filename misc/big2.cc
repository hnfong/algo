// see http://www.cuhkacs.org/~little4/Bo-Blog/read.php/98.htm

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// turns: player 1's turn = 1, player 2's turn = 0.
// TOTAL 1 bit

// T T A A 6 6 7 7 8 8 Q Q Q K K K 2
// TOTAL 17 bits

// valid top cards on the table
// nothing (previous player passed)
// single 6, 7, 8, 10, Q, K, A, 2
// double 6, 7, 8, 10, Q, K, A
// triple Q, K
// TOTAL 18 (need 5 bits)

#define OUTNOTHING 0
#define OUTONESIX 1
#define OUTONESEVEN 2
#define OUTONEEIGHT 3
#define OUTONETEN 4
#define OUTONEQUEEN 5
#define OUTONEKING 6
#define OUTONEACE 7
#define OUTONETWO 8

#define OUTPAIRSIX 9
#define OUTPAIRSEVEN 10
#define OUTPAIREIGHT 11
#define OUTPAIRTEN 12
#define OUTPAIRQUEEN 13
#define OUTPAIRKING 14
#define OUTPAIRACE 15

#define OUTTRIPQUEEN 16
#define OUTTRIPKING 17


const char *moves[] = {
	"PASS",
	"6",
	"7",
	"8",
	"T",
	"Q",
	"K",
	"A",
	"2",

	"66",
	"77",
	"88",
	"TT",
	"QQ",
	"KK",
	"AA",
	"QQQ",
	"KKK",
};


// Grand total 5+17+1 = 23 bits. 2^23 = 8388608

/*
 * - tnT T A A 6 6
 * X X X X X X X X
 * 7 7 8 8 Q Q Q K
 * X X X X X X X X
 * K K 2 [outcard]
 * X X X X X X X X
 */

struct t {
	char winner;
	int mindepth;
};

struct t res[8388608]; // results of minimax saved
int bestmove[8388608]; // best move for the state
int debug = 0;

#define BX(A,B,C,D,E,F,G,H) ((A<<7|B<<6|C<<5|D<<4|E<<3|F<<2|G<<1|H)<<16)
#define B8(A,B,C,D,E,F,G,H) ((A<<7|B<<6|C<<5|D<<4|E<<3|F<<2|G<<1|H)<<8)
#define B0(A,B,C,D,E,F,G,H) ((A<<7|B<<6|C<<5|D<<4|E<<3|F<<2|G<<1|H))

#define ONEWINSMASK   (BX(0,1,1,1,1,1,0,0))
#define ONEWINSVALUE  (0x000000)
#define TWOWINSMASK   (BX(0,1,0,0,0,0,1,1)|B8(1,1,1,1,1,1,1,1)|B0(1,1,1,0,0,0,0,0))
#define TWOWINSVALUE  (BX(0,1,0,0,0,0,0,0))

#define TENMASK BX(0,0,1,1,0,0,0,0)
#define ACEMASK BX(0,0,0,0,1,1,0,0)
#define SIXMASK BX(0,0,0,0,0,0,1,1)
#define SVNMASK B8(1,1,0,0,0,0,0,0)
#define EGTMASK B8(0,0,1,1,0,0,0,0)
#define QUEMASK B8(0,0,0,0,1,1,1,0)
#define KNGMASK (B8(0,0,0,0,0,0,0,1)|B0(1,1,0,0,0,0,0,0))
#define TWOMASK B0(0,0,1,0,0,0,0,0)

#define OUTMASK B0(0,0,0,1,1,1,1,1)

#define TURNMASK BX(0,1,0,0,0,0,0,0)

#define INITIALSTATE (BX(0,0,1,1,1,1,1,1)|B8(1,1,1,1,1,1,1,1)|B0(1,1,1,0,0,0,0,0))

#define PLAYER1TURN(k) ( ( (k) & TURNMASK ) > 0 )

#define SETOUTVALUE(s,v) ( ((s) & (~OUTMASK) ) ^ (v) )

#define RETURN(s,v) do { /*printf("%x is a win for %d: \n", (s), (v)); dumpstate((s));*/ res[(s)] = (v); return v; } while (0)

/* copied from http://aggregate.org/MAGIC/ */
unsigned int ones32(register unsigned int x)
{
        /* 32-bit recursive reduction using SWAR...
	   but first step is mapping 2-bit values
	   into sum of 2 1-bit values in sneaky way */
        x -= ((x >> 1) & 0x55555555);
        x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
        x = (((x >> 4) + x) & 0x0f0f0f0f);
        x += (x >> 8);
        x += (x >> 16);
        return(x & 0x0000003f);
}

/* return s means cannot move. otherwise returns the transformed state according to v */
int tryout(int s, int v)
{
	int k,z,m;

	s = s ^ TURNMASK; // assume a valid move first. if not then just xor it again (at the end)

	// current thing on the table
	m = s & OUTMASK;

	if (v == OUTNOTHING && m != OUTNOTHING) return SETOUTVALUE(s, v);

	if (PLAYER1TURN(s ^ TURNMASK)) {
		// player one's moves
		switch (v) {
			case OUTONETEN:
				switch (m) { case OUTNOTHING: case OUTONESIX: case OUTONESEVEN: case OUTONEEIGHT: break; default: return s ^ TURNMASK; }
				k = s & TENMASK;
				z = ones32(k);
				if (z == 1) return SETOUTVALUE(s ^ BX(0,0,0,1,0,0,0,0), v);
				if (z == 2) return SETOUTVALUE(s ^ BX(0,0,1,0,0,0,0,0), v);
				break;
			case OUTONEACE:
				switch (m) { case OUTNOTHING: case OUTONESIX: case OUTONESEVEN: case OUTONEEIGHT: case OUTONEQUEEN: case OUTONEKING: break; default: return s ^ TURNMASK; }
				k = s & ACEMASK;
				z = ones32(k);
				if (z == 1) return SETOUTVALUE(s ^ BX(0,0,0,0,1,0,0,0), v);
				if (z == 2) return SETOUTVALUE(s ^ BX(0,0,0,0,0,1,0,0), v);
				break;
			case OUTPAIRTEN:
				switch (m) { case OUTNOTHING: case OUTPAIRSIX: case OUTPAIRSEVEN: case OUTPAIREIGHT: break; default: return s ^ TURNMASK; }
				k = s & TENMASK;
				z = ones32(k);
				if (z == 2) return SETOUTVALUE(s ^ BX(0,0,1,1,0,0,0,0), v);
				break;
			case OUTPAIRACE:
				switch (m) { case OUTNOTHING: case OUTPAIRSIX: case OUTPAIRSEVEN: case OUTPAIREIGHT: case OUTPAIRQUEEN: case OUTPAIRKING: break; default: return s ^ TURNMASK; }
				k = s & ACEMASK;
				z = ones32(k);
				if (z == 2) return SETOUTVALUE(s ^ BX(0,0,0,0,1,1,0,0), v);
				break;
		}
	} else {
		// player two's moves
		switch (v) {
			// singles
			case OUTONESIX:
				switch (m) { case OUTNOTHING: break; default: return s ^ TURNMASK; }
				k = s & SIXMASK;
				z = ones32(k);
				if (z == 1) return SETOUTVALUE(s ^ BX(0,0,0,0,0,0,0,1), v);
				if (z == 2) return SETOUTVALUE(s ^ BX(0,0,0,0,0,0,1,0), v);
				break;
			case OUTONESEVEN:
				switch (m) { case OUTNOTHING: break; default: return s ^ TURNMASK; }
				k = s & SVNMASK;
				z = ones32(k);
				if (z == 1) return SETOUTVALUE(s ^ B8(0,1,0,0,0,0,0,0), v);
				if (z == 2) return SETOUTVALUE(s ^ B8(1,0,0,0,0,0,0,0), v);
				break;
			case OUTONEEIGHT:
				switch (m) { case OUTNOTHING: break; default: return s ^ TURNMASK; }
				k = s & EGTMASK;
				z = ones32(k);
				if (z == 1) return SETOUTVALUE(s ^ B8(0,0,0,1,0,0,0,0), v);
				if (z == 2) return SETOUTVALUE(s ^ B8(0,0,1,0,0,0,0,0), v);
				break;
			case OUTONEQUEEN:
				switch (m) { case OUTNOTHING: case OUTONETEN:  break; default: return s ^ TURNMASK; }
				k = s & QUEMASK;
				z = ones32(k);
				if (z == 1) return SETOUTVALUE(s ^ B8(0,0,0,0,0,0,1,0), v);
				if (z == 2) return SETOUTVALUE(s ^ B8(0,0,0,0,0,1,0,0), v);
				if (z == 3) return SETOUTVALUE(s ^ B8(0,0,0,0,1,0,0,0), v);
				break;
			case OUTONEKING:
				switch (m) { case OUTNOTHING: case OUTONETEN:  break; default: return s ^ TURNMASK; }
				k = s & KNGMASK;
				z = ones32(k);
				if (z == 1) return SETOUTVALUE(s ^ B0(0,1,0,0,0,0,0,0), v);
				if (z == 2) return SETOUTVALUE(s ^ B0(1,0,0,0,0,0,0,0), v);
				if (z == 3) return SETOUTVALUE(s ^ B8(0,0,0,0,0,0,0,1), v);
				break;
			case OUTONETWO:
				switch (m) { case OUTNOTHING: case OUTONETEN: case OUTONEACE:  break; default: return s ^ TURNMASK; }
				k = s & TWOMASK;
				z = ones32(k);
				if (z == 1) return SETOUTVALUE(s ^ B0(0,0,1,0,0,0,0,0), v);
				break;

			// doubles
			case OUTPAIRSIX:
				switch (m) { case OUTNOTHING: break; default: return s ^ TURNMASK; }
				k = s & SIXMASK;
				z = ones32(k);
				if (z == 2) return SETOUTVALUE(s ^ SIXMASK, v);
				break;
			case OUTPAIRSEVEN:
				switch (m) { case OUTNOTHING: break; default: return s ^ TURNMASK; }
				k = s & SVNMASK;
				z = ones32(k);
				if (z == 2) return SETOUTVALUE(s ^ SVNMASK, v);
				break;
			case OUTPAIREIGHT:
				switch (m) { case OUTNOTHING: break; default: return s ^ TURNMASK; }
				k = s & EGTMASK;
				z = ones32(k);
				if (z == 2) return SETOUTVALUE(s ^ EGTMASK, v);
				break;
			case OUTPAIRQUEEN:
				switch (m) { case OUTNOTHING: case OUTPAIRTEN: break; default: return s ^ TURNMASK; }
				k = s & QUEMASK;
				z = ones32(k);
				if (z == 3) return SETOUTVALUE(s ^ B8(0,0,0,0,1,1,0,0), v);
				if (z == 2) return SETOUTVALUE(s ^ B8(0,0,0,0,0,1,1,0), v);
				break;
			case OUTPAIRKING:
				switch (m) { case OUTNOTHING: case OUTPAIRTEN: break; default: return s ^ TURNMASK; }
				k = s & KNGMASK;
				z = ones32(k);
				if (z == 3) return SETOUTVALUE(s ^ (B8(0,0,0,0,0,0,0,1) | B0(1,0,0,0,0,0,0,0) ), v);
				if (z == 2) return SETOUTVALUE(s ^ B0(1,1,0,0,0,0,0,0), v);
				break;

			// triples
			case OUTTRIPQUEEN:
				switch (m) { case OUTNOTHING: break; default: return s ^ TURNMASK; }
				k = s & QUEMASK;
				z = ones32(k);
				if (z == 3) return SETOUTVALUE(s ^ QUEMASK, v);
				break;
			case OUTTRIPKING:
				switch (m) { case OUTNOTHING: break; default: return s ^ TURNMASK; }
				k = s & KNGMASK;
				z = ones32(k);
				if (z == 3) return SETOUTVALUE(s ^ KNGMASK, v);
				break;
		}
	}

	return s ^ TURNMASK;
}

void dumpstate(int s) {
	unsigned int i;
	// printf("State: 0x%x\n", s);
	printf("Player 1's cards: ");

	for (i = 0; i < ones32(s & TENMASK); i++) { printf("T"); }
	for (i = 0; i < ones32(s & ACEMASK); i++) { printf("A"); }
	printf("\n");
	
	printf("Player 2's cards: ");
	for (i = 0; i < ones32(s & SIXMASK); i++) { printf("6"); }
	for (i = 0; i < ones32(s & SVNMASK); i++) { printf("7"); }
	for (i = 0; i < ones32(s & EGTMASK); i++) { printf("8"); }
	for (i = 0; i < ones32(s & QUEMASK); i++) { printf("Q"); }
	for (i = 0; i < ones32(s & KNGMASK); i++) { printf("K"); }
	for (i = 0; i < ones32(s & TWOMASK); i++) { printf("2"); }
	printf("\n");

	if ( (s&OUTMASK) == 0 ) {
		printf("Top cards on table: (none)\n\n");
	} else {
		printf("Top cards on table: %s\n\n", moves[s&OUTMASK]);
	}
}

// s = state
// returns 1 if one will win, returns 0 if two will win
// f is just for debugging

struct t minimax(int s) {
	struct t ret;
	int currentplayer;
	int bestchance = 0;

	if (res[s].winner != -1) return res[s];
	if ( (s & ONEWINSMASK) == ONEWINSVALUE) {  // implies player2 turn
		ret.winner = 1;
		ret.mindepth = 1;
		res[s] = ret;
		return ret;
	}
	if ( (s & TWOWINSMASK) == TWOWINSVALUE) { // implies player1 turn
		ret.winner = 0;
		ret.mindepth = 1;
		res[s] = ret;
		return ret;
	}

	currentplayer = PLAYER1TURN(s);

	// assume lose first
	ret.winner = !currentplayer;
	ret.mindepth = 2147483647;
	
	for (int i = 0 ; i < 18; i++)
	{
		int k;
		struct t r;
		k = tryout(s,i);
		if (k == s) continue;
		r = minimax(k);

		if (r.mindepth < ret.mindepth) { ret.mindepth = r.mindepth; }

		if (ret.winner != currentplayer && r.winner == currentplayer) 
		{
			bestmove[s] = i;
			ret.winner = currentplayer;
		} else {
		}

		if (ret.winner != currentplayer && r.winner != currentplayer) { // if i can find no way to win... try the tree with largest depth
			if (bestchance < r.mindepth) {
				bestchance = r.mindepth;
				bestmove[s] = i;
			}
		}

	}

	ret.mindepth ++;

	res[s] = ret;
	return ret;

}

int firstmoverand[] = {
	OUTONESIX, OUTONESEVEN, OUTONEEIGHT, OUTONEQUEEN, OUTONEKING
};

int main() {
	int s;
	int m;
	int m2;
	int compu = 2;
	char buf[10];

	for (unsigned int i = 0 ; i < 8388608; i++) {
		res[i].winner = -1;
		bestmove[i] = -1;
	}

	minimax( INITIALSTATE );

	s = INITIALSTATE;

	dumpstate(s);
	printf("Player 2 moves first. Choose player 1 or player 2?: ");
	scanf("%d", &m);

	if (m == 1) {

		while (1) {
			minimax(s);
			if (s == INITIALSTATE) {
				srand(time(NULL));
				m2 = firstmoverand[rand() % 5];
			} else {
				m2 = bestmove[s];
			}
			printf("*** Player%d plays = %s ***\n", compu, moves[m2]);
			s = tryout(s,m2);
			if ( (s & ONEWINSMASK) == ONEWINSVALUE) { break; }
			if ( (s & TWOWINSMASK) == TWOWINSVALUE) { break; }

			while (1)
			{
				dumpstate(s);
				printf("Your turn. (P for pass)\n");

				scanf("%s", (char*)&buf);

				if (0) {}
				else if (strcasecmp(buf, "P") == 0 || strcasecmp(buf, "PASS") == 0) { m = 0; }
				else if (strcasecmp(buf, "6") == 0) { m = 1; }
				else if (strcasecmp(buf, "7") == 0) { m = 2; }
				else if (strcasecmp(buf, "8") == 0) { m = 3; }
				else if (strcasecmp(buf, "T") == 0) { m = 4; }
				else if (strcasecmp(buf, "Q") == 0) { m = 5; }
				else if (strcasecmp(buf, "K") == 0) { m = 6; }
				else if (strcasecmp(buf, "A") == 0) { m = 7; }
				else if (strcasecmp(buf, "2") == 0) { m = 8; }

				else if (strcasecmp(buf, "66") == 0) { m = 9; }
				else if (strcasecmp(buf, "77") == 0) { m = 10; }
				else if (strcasecmp(buf, "88") == 0) { m = 11; }
				else if (strcasecmp(buf, "TT") == 0) { m = 12; }
				else if (strcasecmp(buf, "QQ") == 0) { m = 13; }
				else if (strcasecmp(buf, "KK") == 0) { m = 14; }
				else if (strcasecmp(buf, "AA") == 0) { m = 15; }

				else if (strcasecmp(buf, "QQQ") == 0) { m = 16; }
				else if (strcasecmp(buf, "KKK") == 0) { m = 17; }
				else { m = -1; }

				if ( m == -1 || tryout(s,m) == s)
				{
					printf("Invalid move. Try again\n");
					continue;
				}

				break;
			}
			s = tryout(s,m);
			if ( (s & ONEWINSMASK) == ONEWINSVALUE) { break; }
			if ( (s & TWOWINSMASK) == TWOWINSVALUE) { break; }

			dumpstate(s);
		}
	} else {
		compu = 1;

		while (1) {

			dumpstate(s);
			while (1)
			{
				printf("Your turn. (P for pass)\n");

				scanf("%s", (char*)&buf);

				if (0) {}
				else if (strcasecmp(buf, "P") == 0 || strcasecmp(buf, "PASS") == 0) { m = 0; }
				else if (strcasecmp(buf, "6") == 0) { m = 1; }
				else if (strcasecmp(buf, "7") == 0) { m = 2; }
				else if (strcasecmp(buf, "8") == 0) { m = 3; }
				else if (strcasecmp(buf, "T") == 0) { m = 4; }
				else if (strcasecmp(buf, "Q") == 0) { m = 5; }
				else if (strcasecmp(buf, "K") == 0) { m = 6; }
				else if (strcasecmp(buf, "A") == 0) { m = 7; }
				else if (strcasecmp(buf, "2") == 0) { m = 8; }

				else if (strcasecmp(buf, "66") == 0) { m = 9; }
				else if (strcasecmp(buf, "77") == 0) { m = 10; }
				else if (strcasecmp(buf, "88") == 0) { m = 11; }
				else if (strcasecmp(buf, "TT") == 0) { m = 12; }
				else if (strcasecmp(buf, "QQ") == 0) { m = 13; }
				else if (strcasecmp(buf, "KK") == 0) { m = 14; }
				else if (strcasecmp(buf, "AA") == 0) { m = 15; }

				else if (strcasecmp(buf, "QQQ") == 0) { m = 16; }
				else if (strcasecmp(buf, "KKK") == 0) { m = 17; }
				else { m = -1; }

				if ( m == -1 || tryout(s,m) == s)
				{
					printf("Invalid move. Try again\n");
					continue;
				}

				break;
			}
			s = tryout(s,m);
			if ( (s & ONEWINSMASK) == ONEWINSVALUE) { break; }
			if ( (s & TWOWINSMASK) == TWOWINSVALUE) { break; }

			minimax(s);
			m2 = bestmove[s];
			printf("*** Player%d plays = %s ***\n", compu, moves[m2]);
			s = tryout(s,m2);
			if ( (s & ONEWINSMASK) == ONEWINSVALUE) { break; }
			if ( (s & TWOWINSMASK) == TWOWINSVALUE) { break; }
			dumpstate(s);
		}
	}

	if ( (s & ONEWINSMASK) == ONEWINSVALUE) { printf("Player 1 wins\n"); }
	if ( (s & TWOWINSMASK) == TWOWINSVALUE) { printf("Player 2 wins\n"); }
}

