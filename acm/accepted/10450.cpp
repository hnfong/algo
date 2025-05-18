#include <iostream>

/*
 @JUDGE_ID: 20044WC 10450 C++
 */

using namespace std;

int main() {
	int i,k,n;
	long long dp[52];

	dp[1] = 2;
	dp[2] = 3;
	
	for (i=3;i<=51;i++) {
		dp[i] = dp[i-1]+dp[i-2];
	};

	cin >> n;
	for (i=1;i<=n;i++) {
		cin >> k;
		cout << "Scenario #" << i << ":" << endl;
		cout << dp[k] << endl;
		cout << endl;
	};
};
