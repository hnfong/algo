#include <random>

namespace util {
int randInt() {
    static std::random_device randDevice;
    static std::default_random_engine randEngine(randDevice());
    static std::uniform_int_distribution<int> uniform_dist;
    return uniform_dist(randEngine);
}

std::string percent(double x) {
    char buf[100];
    snprintf(buf, sizeof(buf), "%.02f", x * 100.0);
    return std::string(buf);
}
}  // namespace util

