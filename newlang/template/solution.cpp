#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::vector<int> w;
    int k;

    while (std::cin >> k)
        w.push_back(k);

    for (auto i = w.begin(); i != w.end(); i++)
        for (auto j = i; j != w.begin(); j--)
            if (*j < *prev(j)) std::swap(*j, *prev(j));

    for (auto it = w.begin(); it != w.end(); it++)
        std::cout << *it << std::endl;
}
