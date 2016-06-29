/*
@JUDGE_ID: 20044WC 10107 C++ "Two Heaps"
 */

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int main () {
	int i,j,m,v,n;
	priority_queue<int> l;
	priority_queue<int> r;
	scanf("%d\n", &m);
	printf("%d\n", m);
	n = 1;
	while (! feof(stdin)) {
		n++;
		scanf("%d\n", &v);
		if (v<=m) { r.push(v); };
		if (v>m) { l.push(-v); };

		if (l.size()>r.size()) {
			r.push(m);
			m = -l.top();
			l.pop();
		};
		if (r.size()-1>l.size()) {
			l.push(-m);
			m = r.top();
			r.pop();
		};
		if (n % 2 == 1) printf("%d\n", m);
		else printf("%d\n", (m+r.top())/ 2);
	};
	return 0;
};

