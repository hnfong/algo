#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (true) {
		if (a > b) a = a % b; else b = b % a;
		if (a == 0) return b;
		if (b == 0) return a;
	};
};

int lcm(int a, int b) { return a/gcd(a,b)*b; };

int main() {
	int n;
	int a,b,k;
	int l;
	int w[1000];
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> a;
		cin >> b;
		w[i] = a + b;
	};
	l = w[0];
	for (int i = 1; i < n ; i++) {
		l = lcm(l,w[i]);
	};

	cout << l << endl;
};

