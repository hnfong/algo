#include <iostream>

using namespace std;

char map [256][256];
int p[] = { 1, 2, 4, 8,16,32,64,128,256 };
char z = 'a'-1;

#define h p[k-1]

void solve(int a, int b,int k, int x , int y, char c ) {
	int d;
	
	/* Mark Hole */
	if (c != '#') { map[a][b] = c; };
	if (k == 0) { return; };
	z++;
	if (z > 'z') { z = 'a'; };
	d = z;

	if ( x < h && y < h ) { /* Upper Left */
		/*    startx	  starty  2^k  x  y  c */
		solve(a		, b	, k-1, x, y, c); // Upper Left
		solve(a+h	, b	, k-1, 0, h, d); // Upper Right
		solve(a		, b+h	, k-1, h, 0, d); // Lower Left
		solve(a+h	, b+h	, k-1, 0, 0, d); // Lower Right
	};
	if ( x >= h && y < h ) { /* Upper Right */
		/*    startx	  starty  2^k  x  y  c */
		solve(a		, b	, k-1, h, h, d); // Upper Left
		solve(a+h	, b	, k-1, x-h, y, c); // Upper Right
		solve(a		, b+h	, k-1, h, 0, d); // Lower Left
		solve(a+h	, b+h	, k-1, 0, 0, d); // Lower Right
	};
	if ( x < h && y >= h ) { /* Lower Left */
		/*    startx	  starty  2^k  x  y  c */
		solve(a		, b	, k-1, h, h, d); // Upper Left
		solve(a+h	, b	, k-1, 0, h, d); // Upper Right
		solve(a		, b+h	, k-1, x, y-h, c); // Lower Left
		solve(a+h	, b+h	, k-1, 0, 0, d); // Lower Right
	};
	if ( x >= h && y >= h ) { /* Lower Right */
		/*    startx	  starty  2^k  x  y  c */
		solve(a		, b	, k-1, h, h, d); // Upper Left
		solve(a+h	, b	, k-1, 0, h, d); // Upper Right
		solve(a		, b+h	, k-1, h, 0, d); // Lower Left
		solve(a+h	, b+h	, k-1, x-h, y-h, c); // Lower Right
	};
	/*
	for (int i = 0 ; i < k ; i ++ ) {
		cout << " " ;
	};
	cout << a << " " << b << " " << k << " " << x << " " << y << " " << c << endl;
	for (int i = b; i < p[k]+b; i++) {
		for (int j = a ; j < p[k]+a ; j++) {
			cout << map[j][i] ;
		};
		cout << endl;
	}; cout << endl; 
	*/
};

int main() {
	int k;
	int x, y;
	cin >> k;
	cin >> y >> x;
	memset(map,' ',sizeof(map));
	
	solve(0,0,k,x-1,y-1, '*');
	for (int i = 0; i < p[k]; i++) {
		for (int j = 0 ; j < p[k] ; j++) {
			cout << map[j][i] ;
		};
		cout << endl;
	};
};

