#include <iostream>
using namespace std;
bool isprime(int k) {
    int sr = sqrt(k+1);
    for (int f = 2; f <= sr; f++) {
        if (k % f == 0) return false;
    }
    return true;
}
int main() {
    int k;
    while (cin >> k) {
        if (isprime(k)) {
            cout << "PRIME" << endl;
        } else {
            cout << "NOT PRIME" << endl;
        }
    }
}
