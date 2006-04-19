#include <algorithm>
#include <iostream>

using namespace std;

int prime(int x) {
	for (int i=2;i<=floor(sqrt((double) x));i++) {
		if (x%i==0) { return false; };
	};
	return true;
};
int main()  {
	int i,j,k,n;
	cin >> n;
	if (n % 2 == 1) {
		if (prime(n-2)) {
			cout << "2 " << (n-2) << endl;
		} else {
			cout << "Impossible" << endl;
		};
		return 0;
	};
	// todo check n
	for (i=0;i<n/2;i++) {
		if (prime(n/2-i) && prime(n/2+i)) {
			cout << n/2-i << " " << n/2+i << endl;
			return 0;
		};
	};
};
