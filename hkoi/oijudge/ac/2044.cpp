#include <iostream>
#include <string>

using namespace std;

int main() {
	int n; int x = 0; string a;
	cin >> n; cin >> a;
	for (int i = 0;i < a.length(); i++) x+=(a[i]-'0')*((i%2)*-2+1);
	cout << (n=((x*-((a.length()%2)*-2+1))+999999)%11)-(n/10*11) << endl;
};
