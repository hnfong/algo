#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
int main() {
	string haystack,needle;
	int i,c;
	getline (cin, haystack);
	getline (cin, needle);
	i = c = 0;
	while (i = haystack.find(needle, i)+1) { c++; };
	cout << c << endl;
};
