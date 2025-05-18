#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int i,j,k,n,z,f;
	vector <int> w;
	int c[40000];
	memset(c,0,sizeof(c));
	cin >> n;
	z = 0;
	for (i=0;i<n;i++) {
		cin >> j;
		w.push_back(j);
		z+=j;
		c[j]++;
	};
	sort(w.begin(),w.end());
	//for (i=0;i<n;i++) { cout << w[i] << endl; };
	printf("%.3f\n", (double) z/n);

	if (n % 2 == 1) {
		printf("%d\n", w[n / 2]);
	} else {
		if ( (w[n/2-1]+w[n/2]) % 2 == 1) {
			printf("%.1f\n", (double) (w[n/2-1]+w[n/2])/2);
		} else {
			printf("%d\n", (w[n/2-1]+w[n/2])/2);
		};
	};
	f = 0; k = 0;
	for (i=1;i<=30000;i++) {
		if (c[i] > f) {
			f = c[i];
			k = i;
		};
	};
	printf("%d\n", k);
};

