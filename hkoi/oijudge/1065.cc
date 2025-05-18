#include <stdio.h>
#include <string.h>

using namespace std;

int greater(char *a, char *b) {
	do {
		if (*a > *b) {
			return 1;
		};
		if (*b > *a) {
			return -1;
		};
		if (*a == *b) {
			a++;
			b++;
		};
	} while ( *a != 0 && *b != 0);
	return 0;
};

int main() {
	char a[100];
	char b[100];
	int lb;
	int la;
	int l;
	bool agtb;

	scanf("%s", (char *) &a);
	scanf("%s", (char *) &b);

	lb = strlen(b);
	la = strlen(a);
	
	if (la > lb) { agtb = true; l = la; } else l = lb;
	if (lb > la) { agtb = false; };

	if (la == lb) {
		if (strncmp(a,b,100) == 0) {
			printf(" %s\n", a);
			printf("-%s\n", b);
			for (int i = 0; i <= la; i++) { printf("-"); }; printf("\n");
			for (int i = 0; i < la; i++) { printf(" "); }; printf("0\n");
			return 0;
		};
		if (greater(a,b) == 1) {
			agtb = true;
		} else {
			agtb = false;
		};
	};

	for (int i = 0; i < (lb / 2) ; i ++ ){
		int k = b[i];
		b[i] = b[lb-i-1];
		b[lb-i-1] = k;
	};
	for (int i = 0 ; i < (la / 2) ; i ++ ) {
		int k = a[i];
		a[i] = a[la-i-1];
		a[la-i-1] = k;
	};

	for (int i = strlen(a); i < 100 ; i ++ ) { a[i] = '0'; };
	for (int i = strlen(b); i < 100 ; i ++ ) { b[i] = '0'; };

	int c[100];


	if (agtb) {
		for (int i = 0  ; i < 100 ; i ++ ) { c[i] = a[i] - b[i]; };
	} else {
		for (int i = 0  ; i < 100 ; i ++ ) { c[i] = b[i] - a[i]; };
	};

	//for ( int i = 100 - 1; i >= 0 ; i -- ) { printf("%d ", c[i]); };
	for (int i = 1 ; i  < 100; i ++ )  {
		c[i] += (c[i-1]-9)/10;
		c[i-1] = (c[i-1] + 100) % 10;
	}; 

	// done doing it 
	

	// first line
	for (int i = 0 ; i < (l-la+1); i++) { 
		printf(" ");
	};
	for (int i = 0 ; i < la; i ++ ) {
		printf("%c", a[la-i-1]);
	}; printf("\n");


	// 2nd line
	
	printf("-");
	for (int i = 1 ; i  <  ( l - lb + 1 ) ;  i ++ ) {
		printf(" ");
	};
	for (int i = 0 ; i < lb ; i++ ) {
		printf("%c", b[lb-i-1]);
	}; printf("\n");

	// 3rd line
	
	for (int i = 0;  i <= (l); i ++ ) printf("-"); printf("\n");

	bool start = false;
	if ( ! agtb ) { printf("-"); } else { printf(" "); };
	
	for ( int i = l-1 ; i >= 0 ; i -- ) { 
		if (c[i] != 0) { start = true; };
		if (start) {
			printf("%d", c[i]);
		} else {
			printf(" ");
		};
	};
	printf("\n");

	return 0;
};

