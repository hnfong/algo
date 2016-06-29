/* note that test data seems crappy, don't depend on this one */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
// #include <algorithm>
// #include <ext/hash_map>
// #include <vector>
#include <map>
// #include <set>
// #include <queue>
#include <iostream>
#include <string>

using namespace std;
// using namespace __gnu_cxx;

// #define debug(...)
#define foreach(v,c) for (typeof((c).begin()) v = (c).begin(); v != (c).end(); v++)

map<char,int> v;

int convertreal(string s, bool hasO) {
	s = s + "ZZZ"; // pad to avoid problems
	int res = 0;
	int i = 0;
	while (i < (int) s.length() - 3) {
		if (s[i] == 'o' || s[i] == 'O') {
			i++;
			hasO = false;
		}
		if (v.count(s[i]) == 0) throw(7); // invalid character
		int k = v[s[i]];
		if (hasO) k *= 1000;

		int kk;
		if (v.count(s[i+1]) != 0) { kk = v[s[i+1]]; } else kk = -1;
		if (hasO) kk *= 1000;

		if ( kk == 5 * k || kk == 10 * k ) {
			i++; i++; res += kk - k;
		} else {
			i++; res += k;
		}
	}
	return res;
}

#define romacro(V,C,VV, CC) while (k >= V) { if (k >= VV) { r = r + CC; k -= VV; } else { r = r + C; k -= V; } }

string romanreal(int k) {
	string r = "";

	romacro(1000,"M",99999, "Z");
	romacro(500,"D", 900, "CM");
	romacro(100,"C", 400, "CD");
	romacro(50,"L", 90, "XC");
	romacro(10,"X", 40, "XL");
	romacro(5,"V", 9, "IX");
	romacro(1,"I", 4, "IV");

	return r;
}

string roman(int k) {
	if (k >= 4000) {
		return romanreal(k / 1000) + "O" + romanreal(k % 1000);
	} else {
		return romanreal(k);
	}
}

int convert(string s) {
	unsigned int i;
	bool found = false;
	for (i = 0 ; i < s.length(); i++) {
		if (s[i] == 'O') { found = true; break; }
	}
	
	int suspectedresult = convertreal(s, found);
	string again = roman(suspectedresult);
	
	if (again == s)
		return suspectedresult;
	throw(7);
}

string up(string s) {
	string res = "";
	for (unsigned i = 0 ; i < s.length(); i++) {
		res += toupper(s[i]);
	}
	return res;
}

int main() {
	string line;
	v['I'] = 1;
	v['V'] = 5;
	v['X'] = 10;
	v['L'] = 50;
	v['C'] = 100;
	v['D'] = 500;
	v['M'] = 1000;
	// debug("%d\n", v.count('i'));
	while ( cin >> line ) {
		unsigned int i;
		for (i = 0 ; i < line.length(); i++) {
			if (line[i] == '+') {
				break;
			}
		}
		if (i == line.length()) {
			printf("INVALID\n");
			continue;
		}
		string a,b;
		a = up(line.substr(0,i));
		b = up(line.substr(i+1));

		try {
			int va = convert(a);
			int vb = convert(b);
			int ans = va + vb;
			printf("%s=%d\n", roman(ans).c_str(), ans );
		} catch (int k) {
			printf("INVALID\n");
		}
	}
	return 0;
}

