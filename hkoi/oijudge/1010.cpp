#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> v;
	vector <int> dp;
	vector <int> l;
	int n,k,j;
	cin >> n;
	for (int i = 0 ; i < n ; i ++ ) { 
		cin >> k;
		v.push_back(k);
	};
	
	for (int i = 0 ; i < n ; i ++ ) { 
		v.push_back(v[i]);
	};
	n = 2*n;
	
	if (v[0] > 0) {
		dp.push_back(v[0]);
	} else {
		dp.push_back(0);
	};

	l.push_back(1);

	for (int i = 1; i < n ; i ++ ) {
		if (dp[i-1] > 0) {
			dp.push_back(dp[i-1] + v[i]);
			l.push_back(l[i-1]+1);
		} else {
			dp.push_back(v[i]);
			l.push_back(1);
		};
		j = i;
		if (l[i] > n/2) { break; };
	};
	k = 0;
	for (int i = j-1; i>= 0 ;i-- ){
		if (k < dp[i]) { k = dp[i] ; };
	};
	cout << k << endl;
};

