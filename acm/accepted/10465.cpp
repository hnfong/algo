#include <iostream>

/*
 @JUDGE_ID: 20044WC 10465 C++
 */
using namespace std;

int main() {
	int a,b,c,k,f,fz,z,i;
	while (cin >> a >> b >> c) {
		if (a > b) { k = a; a = b ; b = k; }
		z = (c/a);
		fz = z;
		k = a * z;
		f = k;
		if (a!=b) {
			for (i=z;i>0;i--) {
				if (f == c) break;
				k = k - a;
				z --;
				if (k+b<=c) {
					k+=b;
					z++;
				};
				if (k > f) {
					f = k;
					fz = z;
				}
			};
		};
		cout << fz;
		if (f != c) cout << " " << c-f ;
		cout << endl;
	};
	return 0;
};
