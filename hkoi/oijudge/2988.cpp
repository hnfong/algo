#include <iostream>

using namespace std;

int main() {
	int n,m,p,k,z,q;
	cin >> n;
	cin >> m;
	cin >> p;
	for (int i = n; i<=m ;i++) {
		if (i==1) continue;
		k = i; z = 0;
		while (k > 0) {
			z += k%10;
			k = k / 10;
		};
		if (p==z) {
			q = 1;
			for (int j = 2; j <= (int) sqrt( (double) i); j++) {
				if (i % j == 0) {
					q = 0; break;
				};
			};
			if (q==1) {
				cout << i << endl;
			};
		};
	};
	cout << "Finish!" << endl;
};
