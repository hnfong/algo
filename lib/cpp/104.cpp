#include <iostream>
#include <utility>
#include <string.h>

#ifndef ONLINE_JUDGE
#include "utils.cpp"
#endif

void printbt(int (&bt)[20][20][20], int i, int j, int step) {
    int k = bt[i][j][step];
    if (step > 0) {
        printbt(bt, i, k, step - 1);
    }
    std::cout << (k + 1) << " ";
}

int main() {
    int n;
    while (std::cin >> n) {
        int found = false;
        double w[20][20];
        double v[20][20];  // moving matrix, step k-1
        double u[20][20];  // moving matrix, step k
        int bt[20][20][20]; // the step of i..j with maximal value at step k
        memset(bt, 0, sizeof(bt));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    w[i][j] = 1;
                    continue;
                }
                std::cin >> w[i][j];
            }
        }

        memcpy(v, w, sizeof(v));
        // dump(v, n, n);

        for (int step = 0; step < n - 1; step++) {
            memcpy(u, v, sizeof(u));

            // multiply the values in v
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (u[i][j] < v[i][k] * w[k][j]) {
                            u[i][j] = v[i][k] * w[k][j];
                            bt[i][j][step] = k;
                            // std::cout << "override " << i << " " << k << " " << j << " " << v[i][j] << std::endl;
                        }
                    }
                }
            }

            memcpy(v, u, sizeof(v));


            // check profit
            for (int i = 0; i < n; i++) {
                if (v[i][i] > 1.01) {  // found! we recurse into the backtrack tree
                    // std::cout << "step=" << step + 2 << std::endl;
                    std::cout << (i + 1) << " ";
                    printbt(bt, i, i, step);
                    std::cout << (i + 1) << std::endl;
                    found = true;
                    break;
                }
            }

            // std::cout << v[1][1] << std::endl;
            // dump(v, n, n);
            if (found) break;
        }

        if (!found) {
            std::cout << "no arbitrage sequence exists" << std::endl;
        }
    }
}
