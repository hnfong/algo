#include <iostream>
#include <vector>
#include <bitset>
#include <stdio.h>

/*
 @JUDGE_ID: 20044WC 661 C++
 */

using namespace std;

int main() {
	bitset<20> w;
	vector<int> v;
	int n,m,c,z,f;
	int i,j,k;
	int ni = 0;
	while (1) {
		v.clear();
		w.reset();
		ni++;
		cin >> n >> m >> c;
		if (n==0&&m==0&&c==0) { return 0; }
		for (i=0;i<n;i++) {
			cin >> k;
			v.push_back(k);
		};
		z = 0;
		f = 0;
		for (i=0;i<m;i++) {
			cin >> k;
			w[k-1] = !w[k-1];
			if (w[k-1]) {
				z += v[k-1];
			} else {
				z -= v[k-1];
			};
			if (z>f) { f = z ; }
		};
		printf("Sequence %d\n", ni);
		if (f > c) {
			printf("Fuse was blown.\n");
		} else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", f);
		};
		printf("\n");
	};
};

