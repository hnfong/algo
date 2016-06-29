#include <stdio.h>
#include <vector>

#include <math.h>

using namespace std;

vector<int> primes;
int dp[10001];

bool isprime(int k) {
	for (int i = 2 ; i <= sqrt(k); i++) {
		if (k % i == 0) return false;
	}
	return true;
}

int main() {
	for (int i = 2 ; i< 10000; i++) {
		if (isprime(i)) {
			primes.push_back(i);
		}
	}

	for (int n = 0; n <= 10000; n++) {
		int z = 0;
		for (unsigned i = 0; i < primes.size() && primes[i] <= n; i++) {
			// check whether there exists a consequtive sequence by just brute checking
			int k = 0;
			for (int j = i; j < primes.size(); j++) {
				k += primes[j];
				if (k == n) {
					z++;
					break;
				}
				if (k > n) break;
			}
		}
		dp[n] = z;
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		printf("%d\n", dp[n]);
	}

	return 0;
	
}
