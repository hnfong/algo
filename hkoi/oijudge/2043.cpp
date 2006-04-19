#include <iostream>

using namespace std;

int main() {
	int w[200][200];
	int n,m,x,y;
	memset(w,0,sizeof(w));
	
	cin >> n;
	for (cin >> m;m>0;m--) {
		cin >> x;
		cin >> y;
		w[x][y] = 1;
	};
	
	cout << (n - 1) * 2 << endl;
	x = 1; y = 1;
	while ( ! ( x == n && y == n ) ) {
		if ( w[x+1][y+1] == 1 ) {
			cout << "E" << endl << "E" << endl << "S" << endl << "S" << endl;
			x+=2; y+=2;
		} else {
			if (w[x+1][y]==0) {
				cout << "S" << endl << "E" << endl;
				x+=1; y +=1;
			} else {
				cout << "E" << endl << "S" << endl;
				x+=1; y +=1;
			};
		};
	};
};

