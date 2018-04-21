#include "testcase.h"

#include <iostream>
#include <vector>
#include <chrono>

// "Meyers Singleton"
std::vector<TestCase *> &getRegistry() {
    static std::vector<TestCase *> registry_;
    return registry_;
}

int TestCase::runTests() {
    int failures = 0;
    auto &registry = getRegistry();
    std::cout << "Num of tests: " << registry.size() << std::endl;
    for (auto it = registry.begin(); it != registry.end(); it++) {
        std::cerr << "Running test " << (*it)->name() << "... ";
        int result = (*it)->run();
        if (result) {
            std::cerr << "PASSED" << std::endl;
        } else {
            std::cerr << "FAILED" << std::endl;
            failures++;
        }
    }

    return failures == 0;
}

TestCase *TestCase::registerTest(TestCase *t) {
    auto &registry = getRegistry();
    registry.push_back(t);
    return t;
}
