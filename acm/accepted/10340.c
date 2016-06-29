#include <stdio.h>
#include <string.h>
/*
	@JUDGE_ID:  20044WC 10340 C "Why not on9"
*/

int main() {
	char c;
	char sub[100000];
	char sup[100000];
	int subl, supl;
	int i,j,k;
	int answer;

	while (!feof(stdin)) {
		i = j = k = 0;
		while (1) {
			c = getc(stdin);
			if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9'))) {
				sub[i] = c;
				i++;
			} else { sub[i] = 0; break; };
		};

		i = 0;
		while (1) {
			c = getc(stdin);
			if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9'))) {
				sup[i] = c;
				i++;
			} else {  sup[i] = 0;break; };
		};


		subl = strlen(sub);
		supl = strlen(sup);
		if ((subl == 0) && (supl == 0)) { return 0; };

		answer = 1;
		for (i=0;i<subl;i++) {
			for (j=k;j<supl;j++) {
				if (sub[i] == sup[j]) { k = j+1; j = 0; break; };
			};
			if (j == supl) { answer = 0; break; };
		};
		if (answer) { printf("Yes\n"); } else { printf("No\n"); };
	};
	return 0;
};

