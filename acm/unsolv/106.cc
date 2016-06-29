#include <stdio.h>
#include <math.h>
#include <set>

int gcd(int a, int b) {
	while (a > 0 && b > 0) {
		if (a>b)  a = a % b;
		else b = b % a;
	};
	return (a==0?b:a);
};

std::set <int> yesnum;
int triples;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		triples = 0;
		int threshold = (int) sqrt(n) + 2;
		while (threshold * threshold > n) {
			threshold --;
		};
		for (int x = 1; x <= n; x++) {
			long long k = (long long) x*x;
			for (int i = x ; i > 0; i-- ) {
				if (k % i == 0) {
					int t = k/i + i;
					if (t % 2 != 0) continue;
					int y = t/2 - i; 
					int z = t / 2;
					if (y <= x) continue;
					if (z > n) break;
					if (gcd(x,y) == 1 && gcd(y,z) == 1 && gcd(z,x) == 1)  {
						triples++;
						//printf("%d^2 + %d^2 = %d^2 [ %d ]\n", x,y,z, i);
					};
				};
			};
		};
		printf("%d\n", triples);
	};
};
