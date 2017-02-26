#include <iostream>

#ifndef ONLINE_JUDGE
#include "count_3np1.cpp"
#endif

int main() {
    int a, b;
    while (std::cin >> a >> b) {
        int a_ = std::min(a, b);
        int b_ = std::max(a, b);
        int x = 0;
        for (int k = a_; k <= b_; k++) {
            x = std::max(x, count_3np1(k));
        }
        std::cout << a << " " << b << " " << x << std::endl;
    }
}
