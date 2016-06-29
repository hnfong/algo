#include <iostream>
using namespace std;

long long n;

int main()
{
	cin >> n;
	long long z = 0;
	int cnt = 0;

	for (int k = 60; k >=0; k--)
	{
		if (n & (1LL << k)) {
			z += k * (1LL<<(k-1));
			z += cnt * (1LL<< k);
			cnt++;
		}
	}

	cout << z + cnt << endl;
}
