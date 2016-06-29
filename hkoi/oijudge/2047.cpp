#include <iostream>

using namespace std;

int max(int a, int b) {
	return (a > b ? a : b );
};
int min(int a, int b) {
	return (a < b ? a : b );
};

int main() {
	int n1,n2,k1,k2,c;
	
	int a1[1000],b1[1000];
	int a2[1000],b2[1000];
	
	cin >> n1;
	for (int i = 0;i < n1;i++ ){
		cin >> a1[i] >> b1[i];
	};
	cin >> n2;
	for (int i = 0;i < n2;i++ ){
		cin >> a2[i] >> b2[i];
	};

	c = 0;
	for (int i = 0; i < n1 ; i ++ ) {
		for (int j = 0; j < n2 ; j ++ ) {
			if (max(a1[i], a2[j]) <= min(b1[i], b2[j])) {
				c++;
			};
		};
	};
	cout << c << endl;
	for (int i = 0; i < n1 ; i ++ ) {
		for (int j = 0; j < n2 ; j ++ ) {
			if (max(a1[i], a2[j]) <= min(b1[i], b2[j])) {
				cout << max(a1[i], a2[j]) << " " << min(b1[i], b2[j]) << endl;
			};
		};
	};
};
