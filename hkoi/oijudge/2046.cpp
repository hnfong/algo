#include <iostream>

using namespace std;

int main() {
	int n, k, v[10000];
	long double w[10000];
	cin >> n >> k;
	for (int i = 0 ; i < n ; i ++ ) {
		cin >> v[i];
	};

	int z = 0;
	long double d = 0;

	for (int i=0;i<n;i++) {
		if (i >= k) {
			w[i] = (long double) z/k;
			d = d + abs(w[i] - v[i]);
		};
		z = z + v[i];
		if (i >= k) {
			z = z - v[i-k];
		};

	};
	int t = (int) roundl((long double) d * 100 / (n-k) );
	cout << t / 100 << "." << (t /10) % 10 << t % 10 << endl;
	
};

