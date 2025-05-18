#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	
	int p, q, n;
	long long a[10];

	while (true) {
		char s[1000];
		char *z;
		fgets(s, 1000, stdin);
		z = strstr(s, " ");
		z++;
		if (strstr(z, " ") == NULL) {
			break;
		};

		sscanf(s, "%d %d %d", &p , &q, &n);
		
		if (n==0){
			cout << 2 << endl;
			continue;
		}

		if ((p==0) && (n % 2==1)) {
			cout << 0 << endl;
			continue;
		}
		
		a[1] = p;
		a[2] = p*p-2*q;
		for (int i=3; i<=n; i++){
			a[i % 3] = p * a[(i-1) % 3] - q * a[(i-2) % 3];
		};

		cout << a[n % 3] << endl;
	}

	return 0;
}

