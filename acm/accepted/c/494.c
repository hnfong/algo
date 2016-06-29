#include <stdio.h>
/*
	@JUDGE_ID:  20044WC 494 C "Siliconism - LFM"
*/
int main() {
	int i,j,k;
	char c;
	int state;

	while (1) {
		state = 0;
		k = 0;
		while (1) {
			c = fgetc(stdin);
			if (c == EOF) { return 0; };
			if (c == 10) { break; };
			if ((((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) && (state == 0)) { state = 1; k ++ ; };
			if (!(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))) { state = 0 ; } ;
		};
		printf("%d\n", k);
	};
};
