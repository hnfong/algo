#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <stdio.h>

/*
@JUDGE_ID: 20044WC 10282 C++
*/

using namespace std;

int main() {
	int i,j,k,n;
	map <string, string> w;
	char s[30];
	string s1,s2;
	char *c;
	while (true) {
		memset(s,0,sizeof(s));
		fgets(s,30,stdin);
		s[strlen(s)-1]=0;
		if (strlen(s)==0) { break; };
		c = strstr(s," ");
		*c = 0;
		s1 = s;
		s2 = c+1;
		w[s2] = s1;
	};
	while (!feof(stdin)) {
		memset(s,0,sizeof(s));
		fgets(s,20,stdin);
		if (strlen(s)==0) { break; };
		s[strlen(s)-1] = 0;
		if (strlen(s)==0) { break; };
		s1 = s;
		if (w[s1].empty()) {
			printf("eh\n");
		} else  {
			printf("%s\n", w[s1].c_str());
		};
	};
	return 0;
};
