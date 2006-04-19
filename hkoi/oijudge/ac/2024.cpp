#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct dat {
	int a,b;
};

int comp(dat x, dat y) {
	return x.b < y.b;
};
int main() {
	int i,j,k,n,m;
	dat t;
	dat w[10000];
	int a[100];
	cin >> n >> m ;
	for (i=0;i<n;i++) { a[i] = i+1; };
	for (i=0;i<m;i++) {
		cin >> w[i].a >> w[i].b;
	};
	stable_sort(w,w+m,comp);

	for (i=0;i<m;i++) {
		k = a[ w[i].a-1 ];
		a[ w[i].a-1 ] = a[ w[i].a ];
		a[ w[i].a ] = k;
	};

	for (i=0;i<n-1;i++) {
		cout << a[i] << " " ;
	}; cout << a[n-1] << endl;

	cin >> n;
	for (i=0;i<n;i++) {
		cin >> a[i];
	};
	m = 0;
	for (i=0;i<n;i++) {
		for (j=i;j>0;j--) {
			if (a[j]<a[j-1]) {
				w[m].a = j;
				w[m].b = m+1;
				k = a[j];
				a[j] = a[j-1];
				a[j-1] = k;
				m++;
			};
		};
	};
	cout << m << endl;
	for (i=0;i<m;i++) {
		cout << w[i].a << " " << (m-w[i].b+1) << endl;
	};
	return 0;
};

