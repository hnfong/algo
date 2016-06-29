#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int minpos(int a,int b) {
	if (a == -1 && b == -1) { return -1; };
	if (a == -1) {
		b+=4;
		return b;
	};
	if (b == -1) {
		a+=2;
		return a;
	};
	a+=2; b+=4;
	if (a < b) { return a; } else { return b; };
};
int nextquote(string s, int a) {
	int e;
	e = a;
	while (((int)s.find("\\\"",e)==(int)s.find("\"",e)-1 ) && ( (int) s.find("\\\"",e) >= 0)) {
		e = s.find("\"", e)+1;
	};
	return (int) s.find("\"", e);
};
int process(string s) {
	int t1,t2;
	while ((t1 = nextquote(s, 0)) >= 0) {
		if ((t2 = nextquote(s, t1+1)) >= 0) {
			s.replace(t2, 1, "''");
			s.replace(t1, 1, "``");
		} else {
			s.replace(t1, 1, "");
		};
	};
	cout << s ;
};
int main() {
	char c[500000];
	string s;
	int e,f,k,n,l;
	cin.read(c,sizeof(c));
	s = (string) c;
	s = s.substr(0, s.find("\\endinput")+9);
	e = 0;
	f = 0;
	while (true) {
		f = minpos(s.find("\n\n", e), s.find("\\par", e));
		if (f == -1) { f = s.length(); };
		process(s.substr(e, f-e));
		if (f == s.length()) { break; };
		e = f;
	};
	cout << endl;
	return 0;
};
