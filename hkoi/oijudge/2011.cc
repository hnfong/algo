#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char gctmp[17] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int gc = 0;
int n = 0;
char s[100];

char xr(char a, char b) {
	if (a == '0') { return b; };
	if (a == '1') { if (b == '1') return '0'; if (b == '0') return '1'; };
	throw(0);
	return 0;
};

void gcodegen(int k) {
	if (strlen(gctmp) == 16) {
		char t[100];
		strcpy(t, s);
		for (int i = 0 ; i < n; i ++ ) {
			t[i] = xr(t[i], gctmp[i+ (16-n)]);
		};
		t[n] = 0;
		printf("%s\n", t);
		gc++;
		if (gc >= (1 << n)) {
			exit(0);
		};
	};
	if (k >= 16) {
		return;
	};
	gctmp[k] = '0';
	gcodegen(k+1);
	gctmp[k] = '1';
	gcodegen(k+1);
};

int main() {
	fgets(s, 18, stdin);
	if (!feof(stdin)) {
		fgets(s, 18, stdin);
	};
	int len = strlen(s);

	if (s[len-1] == '\n') {
		s[len-1] = 0;
		len --;
	};

	n =  len;

	gcodegen(0);
	
};
