#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct m {
	int x,y;
	bool operator<(const m& v) const { 
		return ( (long long) x*x + y * y < (long long) v.x * v.x + v.y * v.y);
	}
	m (int a, int b) {
		x = a;
		y = b;
	};
};

int main() {
	vector <m> v;
	int x,y;
	int n;
	cin >> n;
	for (;n>0;n--) {
		cin >> x >> y;
		v.push_back( m(x,y));
	};

	sort(v.begin(), v.end());

	for ( vector<m>::iterator i = v.begin() ; i != v.end(); i++ ) {
		cout << i->x << " " << i-> y << endl;
	};
};

