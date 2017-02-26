#include <utility>

int count_3np1(int n) {
    int z = 1;
    while (n > 1) {
        if (n % 2) {
            n = 3 * n + 1;
        } else {
            n = n / 2;
        }
        z++;
    }
    return z;
}
