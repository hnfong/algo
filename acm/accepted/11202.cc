#include <iostream>


int main() {
	int n;
	std::cin >>n;
	while (n--) {
		int a,b;
		std::cin >> a >> b;
		if (a == b) {
			int m = (a + a%2) / 2;
			std::cout << (m*m+m)/2 << std::endl;
		} else {
			a += a%2;
			b += b%2;
			std::cout << a*b/4 << std::endl;
		}
	}
}
