#include <iostream>
#include <stdio.h>
#include <cmath>

/*
 @JUDGE_ID: 20044WC 579 C++
 */

using namespace std;

int main() {
	double h,m,t;
	char c;
	int a,b;
	while(cin >> a >> c >> b ) {
		if (a==0) { break; };
		m = b*6 ;
		h = a*30+(double) m* ( (double) 5/60   );
		while (m>=360) {m-= 360;};
		while (h>=360) {h-= 360;};
		t = abs(h-m);
		if (t>180) { t = 360 - t; };
		printf("%.3f\n", t);
	};
};
