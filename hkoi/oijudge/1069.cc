#include <iostream>




int power(int x, int n) {
	if (n == 0) return 1;
	int c;
	c = power(x, n/2);
	if (n % 2 == 0) { return (c * c ); } else { return (c * c * x) ; };
};

int main() {
	int n, p[7], m, k[7];
	int c, z;
	c = 0;

	cin >> n;
	cin >> m;
	cout << power(n,m) << endl;
	for (int i = 0 ; i < n ; i ++ ) { 
		cin >> k[i] >> p[i] ;
	};
	
};
