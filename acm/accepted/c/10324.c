#include <stdio.h>
/*
@JUDGE_ID:  20044WC 10324 C "I WANT I WANT"
*/
int main() {
	int i;
	int dp[1100000];
	int n;
	int s;
	char c, l;
	int a,b,t;
	int whichset;

	whichset = 0;
	while (! feof(stdin)) {
		whichset ++;
		l = ' ';
		s = 0; n = 0; a = b = t = 0;
		while (1) {
			c = getc(stdin);
			if (c == EOF) { return 0; };
			if (c == '\n') { break; };
			if ((c == l) && (s > 0)) { dp[s] = dp[s-1] + 1; } else { dp [s] = 0; };
			s ++;
			l = c;
		};
		
		printf("Case %d:\n", whichset);
		scanf("%d", &n);

		for (i=1;i<=n;++i) {
			scanf("%d %d\n", &a, &b);
			if (a > b) { t = b; b = a; a = t; };
			if ((dp[b] - (b-a) ) >= 0) { printf("Yes\n"); } else { printf("No\n"); };
		};
	};
	return 0;
};
