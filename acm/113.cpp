#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
	long double i,j,k,n,p;
	while (true) {
		cin >> n;
		cin >> p;
		if (!cin) { break; }
		cout << floor( exp( log(p)/n ) + 0.5 ) << endl;
	};
	return 0;
};

