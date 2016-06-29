#include <iostream>


using namespace std;

char c[10][10];

int ox[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int oy[8] = {-1, 0, 1, 1,-1,-1, 0, 1};

int tryput(int x, int y) {
	int ret = 0;
	int a, b, z, t;
	if (c[x][y] != '.') return 0;
	for (int i = 0 ; i < 8 ; i ++ ) {
		a = x;
		b = y;
		z = 0;
		t = 0;
		while (8 > a && a >= 0 && 8 > b && b >= 0) {
			a = a + ox[i];
			b = b + oy[i]; // increment one space
			z ++;
			if (c[a][b] == 'W') {
				t = z - 1;
				break;
			};
			if (c[a][b] == '.') { break; };
		};

		ret += t;
	};
	return ret;
};


int main() {
	int k,f;
	for (int i = 0 ; i < 8 ; i ++ ) { 
		for (int j = 0 ; j < 8 ; j ++ ) { 
			cin >> c[i][j];
		}
	};

	f = 0;
	for (int i = 0 ; i < 8 ; i ++ ) {
		for ( int j = 0 ; j < 8 ; j ++ ) {
			k  = tryput(i,j);
			if (k > f) {
				f = k; };
		};
	};

	cout << f << endl;

};

