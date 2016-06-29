#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
set <int> s[1000];
set <int> gave;
set <int> giving;
vector <int> v;
int n;

int give(int p) {
	set <int> c;
	if (gave.count(p) > 0) return 0;
	if (giving.count(p) > 0) return -1;
	giving.insert(p);
	
	while (!s[p].empty()) {
		if (give( *(s[p].begin()) ) == -1) return -1;
	};
	gave.insert(p);
	v.push_back(p);
	for (int i = 0;i <n ;i ++) {
		c.clear();
		set_difference(s[i].begin(), s[i].end(), gave.begin(), gave.end(), insert_iterator<set<int> > (c, c.begin()));
		s[i] = c;
	};
	return 0;
};

int main () {
	int k,m;
	cin >> n;
	for (int i = 0 ; i < n ; i ++ ){
		for (cin >> k; k > 0; k -- ) {
			cin >> m;
			s[m-1].insert(i);
		};
	};

	for (int i = 0 ; i < n ; i ++ ) {
		if (give(i) == -1) {
			cout << "No Solution" << endl;
			return 0;
		};
	};
	for (int i = 0 ; i < n-1 ; i ++ ){
		cout << v[i]+1 << " ";
	};
	cout << v[n-1]+1 << endl;
};

