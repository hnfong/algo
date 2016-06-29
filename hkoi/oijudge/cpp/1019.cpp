#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
	long long int w[50000];
	priority_queue<int> q;
	long long int i,j,k,n,z;
	scanf("%d\n", &n);
	for (i=0;i<n;i++) {
		scanf("%d\n", &k);
		k = -k;
		q.push(k);
	};
	z = 0;
	for (i=0;i<n-1;i++) {
		k = q.top();
		q.pop();
		k = k + q.top();
		z = z + k;
		q.pop();
		q.push(k);
	};
	cout << (-z) << endl;
	return 0;
};
