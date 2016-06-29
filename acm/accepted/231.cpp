#include <stdio.h>
#include <iostream>
#include <vector>

/*
 @JUDGE_ID: 20044WC 231 C++
 */

using namespace std;

struct dat {
	int v;
	int dp;
};

int main() {
	vector<dat> w;
	
	int i,ni,k,f;
	dat t;
	ni = 0;
	while (true) {
		w.clear();
		// first input
		cin >> t.v;
		if (t.v==-1) { break; }
		ni ++;
		t.dp = 1;
		w.push_back(t);
		while (cin >> t.v && t.v != -1) {
			f = 0;
			for (vector<dat>::iterator it=w.begin();it != w.end();it++) {
				if ((*it).dp > f && (*it).v > t.v) {
					f = (*it).dp;
				};
			};
			t.dp = f + 1;
			w.push_back(t);
		};
		f = 0;
		for (vector<dat>::iterator it=w.begin();it != w.end();it++) {
			if ((*it).dp > f && (*it).v > t.v) {
				f = (*it).dp;
			};
		};
		if (ni > 1) cout << endl;
		cout << "Test #" << ni << ":" << endl;
		cout << "  maximum possible interceptions: " << f << endl;
	};
};
