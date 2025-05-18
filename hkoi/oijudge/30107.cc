#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int k;
	int m;
	vector <int> r;
	vector <int> l;
	int rs, ls;
	rs = 0;
	ls = 0;
	// cin >> m;
	scanf("%d", &m);
	// cout << m << endl;
	printf("%d\n", m);
	// while (cin >> k) {
	while ( scanf("%d", & k ) != EOF ) {
		if (k >= m) {
			r.push_back(-k);
			push_heap(r.begin(), r.end());
			rs ++;
		} else {
			l.push_back(k);
			push_heap(l.begin(), l.end());
			ls ++;
		}

		while (rs > ls) {
			l.push_back(m);
			push_heap(l.begin(), l.end());

			m = - *(r.begin());
			
			pop_heap(r.begin(), r.end());
			r.pop_back();

			rs--;
			ls++;
		};
		while (ls > rs + 1) {
			r.push_back(-m);
			push_heap(r.begin(), r.end());

			m = *(l.begin());
			pop_heap(l.begin(), l.end());
			l.pop_back();

			ls--;
			rs++;
		};
		
		/*
		cout << "START" << endl;
		for ( std::vector<int>::iterator it = l.begin(); it != l.end(); it ++) {
			cout << *it << " ";
		}; cout << endl;
		cout << m << endl;
		for ( std::vector<int>::iterator it = r.begin(); it != r.end(); it ++) {
			cout << *it << " ";
		}; cout << endl;
		cout << "END" << endl;
		*/

		if (rs == ls) {
			// cout << m << endl;
			printf("%d\n", m);
		} else {
			// cout << (int) (m + (*l.begin())) / 2 << endl;
			int t = (  (( unsigned ) m + (*l.begin())) / 2);
			printf("%d\n", t );
		};
	};
};

