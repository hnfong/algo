#include <iostream>

void move(int N, char s, char t, char x) {
    if (N) {
        move(N - 1, s, x, t);
        std::cout << s << ' ' << t << std::endl;
        move(N - 1, x, t, s);
    }
}

int main() {
    int k;
    std::cin >> k;
    move(k, 'A', 'C', 'B');
}
