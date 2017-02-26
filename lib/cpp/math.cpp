template <typename T> T gcd(T a, T b) {
    while (a && b) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a == 0 ? b : a;
}
