#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>

/*
 @JUDGE_ID: 20044WC 10193 C++
 */

using namespace std;

int main() {
	int i,j,k,ni,nt,n,a,b;
	string s1,s2;
	cin >> nt;
	for (ni=1;ni<=nt;ni++) {
		cin >> s1;
		cin >> s2;
		a = 0;
		for (string::iterator it=s1.begin();it != s1.end();it++) {
			a *= 2;
			a = a + (int) (*it-48);
		};
		b = 0;
		for (string::iterator it=s2.begin();it != s2.end();it++) {
			b *= 2;
			b = b + (int) (*it-48);
		};
		while (a>0&&b>0) {
			if (a>b) {a = a % b;} else { b = b % a; };
		};
		if (b>a) { a = b; };
		if (a > 1) {
			cout << "Pair #" << ni << ": All you need is love!" << endl;
		} else {
			cout << "Pair #" << ni << ": Love is not all you need!" << endl;
		};
	};
};
