#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n,k,r;
	int i;
	int sorted;
	string las;
	string s;
	cin >> n >> r >> k;
	cin >> s;
	sort(s.begin(),s.end());
	las = "";
	while (k > 0) {
		sorted = true;
		for (i=1;i<r;i++) {
			if (s.c_str()[i]<s.c_str()[i-1]) {
				sorted = false;
				break;
			};
		};
		if (sorted && las.substr(0,r) != s.substr(0,r) ) {
			printf("%s\n", s.substr(0,r).c_str());
			las = s.substr(0,r);
			k--;
		};
		next_permutation(s.begin(), s.end());
	};
};
