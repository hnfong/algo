#include <iostream>
#include <stdio.h>
#include <string>

/*
 @JUDGE_ID: 20044WC 455 C++
 */

using namespace std;

int main() {
	string s;
	string t;
	int n;
	int i,j;
	bool b;
	for (cin >> n;n>0;n--) {
		cin >> s;
		for (i=1;i<=40;i++) {
			t = s.substr(0,i);
			b = true;
			for (j=0;j<s.length();j+=i) {
				if (t!=s.substr(j,i)) {
					b = false;
					break;
				};
			};
			if (b) {
				cout << i << endl;
				if (s.length()%i>0) { while (1) {}; };
				break;
			};
		};
		if (!b) { cout << s.length() << endl; };
		if (n>1) cout << endl;
	};
};

