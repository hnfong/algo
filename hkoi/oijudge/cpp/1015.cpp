#include <iostream>
#include <string>
#include <stack>
using namespace std;

void result(string s) {
	cout << s << endl;
	exit(0);
};

int main() {
	stack<char> s;
	char c;
	char t;
	while ( cin >> c ) {
		if (c == '(' || c == '{' || c == '[') { s.push(c); };
		if (c == ')' || c == '}' || c == ']') {
			if (!s.empty()) {
				t = s.top();
				if (c == ')' && t != '(') { result("No"); };
				if (c == ']' && t != '[') { result("No"); };
				if (c == '}' && t != '{') { result("No"); };
				s.pop();
			} else {
				result("No");
			};
		};
	};

	if (s.empty()) { result("Yes"); } else { result("No"); };
};

