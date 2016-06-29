#include <iostream>
#include <cmath>
#include <vector>

/*
 @JUDGE_ID: 20044WC 10392 C++
 */

using namespace std;

int main() {
	vector<int> p;
	unsigned int i,j,n;
	long long int k;
	bool b;
	unsigned int c;
	// preprocess
	
	p.push_back(2);
	i = 3;
	while (i <= 100000) {
		b = true;
		c = (unsigned int) floor(sqrt((double) i));
		for (j=3;j<=c;j+=2) {
			if (i%j==0) { b= false; break; };
		};
		if (b) p.push_back(i);
		i+=2;
	};


	while ( cin >> k && k != -1 ) {
		for (vector<int>::iterator x = p.begin();x!=p.end();x++) {
			while (k%*x==0) {
				k = k / *x;
				cout << "    " << *x << endl;
			};
		};

		for (j=100001;j<=floor(sqrt((long double) k));j+=2) {
			while (k%j==0) {
				cout << "    " << j << endl;
				k = k / j;
			};
		};
		if (k>1) cout << "    " << k << endl;
		cout << endl;
	};
};

