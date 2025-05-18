#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

/*
 @JUDGE_ID: 20044WC 855 C++
 */

using namespace std;

int main() {
	int t,i,j,k,n,s,a;
	int ws[50000];
	int wa[50000];
	 
	for (cin >> t;t>0;t--) {
		cin >> s >> a >> n;
		for (i=0;i<n;i++) {
			cin >> ws[i] >> wa[i] ;
		};
		sort(ws,ws+n);
		sort(wa,wa+n);
		cout << "(Street: " << ws[ (n-1) / 2 ] << ", Avenue: " << wa[ (n-1) / 2 ] << ")" << endl;
	};
	
};
