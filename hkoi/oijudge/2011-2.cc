#include <stdio.h>
#include <string.h>

char s[20];
char g[32768][17];
int n = 0;

int pow[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};

char nxor(char a, char b) {
	if (a == '0') { return b; };
	if (a == '1') { 
		if ( b == '1') return '0';
		if ( b == '0') return '1';
	};
	throw(0);

};

void greycode(int k) {
	if (k <= 1) {
		g[0][0] = '0';
		g[1][0] = '1';
		return;
	};
	greycode(k-1);
	
	for (int i = 0; i < pow[k-1]; i++ ) {
		g[i][k-1] = '0';
	};
	for (int i = pow[k-1]; i < pow[k]; i++ ) {
		g[i][k-1] = '1';
		for (int j = 0; j < k-1; j ++ ) {
			g[i][j] = g[pow[k]-i-1][j];
		};
	};
};

int main() {
	fgets(s,11,stdin);
	fgets(s,11,stdin);
	memset(g,0,sizeof(g));

	n = strlen(s);
	if (s[n-1] == '\n') {
		s[n-1] = 0;
		n--;
	};

	greycode(n);

	for (int i = 0 ; i < pow[n] ; i ++ ) {
		for (int j = 0 ; j < n ; j ++  ) {
			printf("%c", nxor (s[j], g[i][j]));
		};
		printf("\n");
	};
};
