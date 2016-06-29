#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

struct dat {
	int d, m, y;
	char s[100];
};

string hc[12] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
int main() {
	dat d[100];
	dat t;
	char *c;
	char *c2;
	int i,j,k,n;
	scanf("%d\n", &n);
	for (i=0;i<n;i++) {
		fgets(d[i].s,100, stdin);
		c = strstr(d[i].s, ",");
		*c = 0;
		d[i].d = atoi(d[i].s);
		*c = ',';
		c++; c++;
		c2 = strstr(c, " ");
		*c2 = 0;
		for (j=0;j<12;j++) {
			if (hc[j] == c) {
				d[i].m = j+1;
				break;
			};
		};
		*c2 = ' ';
		c2++;
		d[i].y = atoi(c2);
	};

	for (i=0;i<n;i++) {
		for (j=i;j>0;j--) {
			if (d[j].d < d[j-1].d) {
				t = d[j];
				d[j] = d[j-1];
				d[j-1] = t;
			};
		};
	};
	for (i=0;i<n;i++) {
		for (j=i;j>0;j--) {
			if (d[j].m < d[j-1].m) {
				t = d[j];
				d[j] = d[j-1];
				d[j-1] = t;
			};
		};
	};
	for (i=0;i<n;i++) {
		for (j=i;j>0;j--) {
			if (d[j].y < d[j-1].y) {
				t = d[j];
				d[j] = d[j-1];
				d[j-1] = t;
			};
		};
	};

	for (i=0;i<n;i++) {
		printf("%s", d[i].s);
	};
};

