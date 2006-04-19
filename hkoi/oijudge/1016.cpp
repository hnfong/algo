#include <iostream>
using namespace std;

int main() {
	int v[100000];
	int dp[100000];
	int k,f,n,z;

	z = 0;
	cin >> n;
	for (int i = 0 ; i < n ; i ++ ) {
		cin >> v[i];
		z += v[i];
	};

	dp[0] = (v[0]>0 ? v[0] : 0);

	for (int i = 1 ; i < n ; i ++ ) {
		if (dp[i-1] > 0) {
			dp[i] = dp[i-1] + v[i];
		} else {
			dp[i] = v[i];
		};
	};

	f  = 0;
	for (int i = 0 ; i < n ; i ++ ) {
		if (dp[i] > f) f = dp[i];
	};

	// reverse it!
	for (int i = 0; i < n ; i ++ ) { v[i] = -v[i]; };
	
	dp[0] = (v[0]>0 ? v[0] : 0);

	for (int i = 1 ; i < n ; i ++ ) {
		if (dp[i-1] > 0) {
			dp[i] = dp[i-1] + v[i];
		} else {
			dp[i] = v[i];
		};
	};

	k  = 0;
	for (int i = 0 ; i < n ; i ++ ) {
		if (dp[i] > k) k = dp[i];
	};

	// take the negation of it...  <== z + k <== z - ( - k ) <== z.remove ( most negative chain )
	if ((z + k) > f) { f = z + k ; };
	
	cout << f << endl; 

};
