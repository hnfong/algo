#include <iostream>
#include <algorithm>
#include <string.h>

#ifndef ONLINE_JUDGE
#include "utils.cpp"
#endif

bool bigger(int *a, int *b, int k) {
    for (int i = 0; i < k; i++) {
        if (a[i] <= b[i]) return false;
    }
    return true;
}

int n, k;
int dp[30];
int bt[30];
int w[30][10];

int search(int x) {
    if (dp[x] != 0) return dp[x];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        // if x < i then
        if (bigger(w[i], w[x], k)) {
            if (search(i) > ans) {
                ans = search(i);
                bt[x] = i;
            }
        }
    }
    // std::cout << "search(" << x << ") -> " << ans + 1 << ", " << bt[x] << std::endl;
    dp[x] = ans + 1;
    return dp[x];
}

int main() {
    while (std::cin >> n >> k) {
        memset(dp, 0, sizeof(dp));
        memset(bt, 0, sizeof(bt));

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0; j < k; j++) {
                std::cin >> w[i][j];
            }
            std::sort(w[i], w[i] + k);
        }
        // dump(w, n, k);

        int f = 0;
        int best = -1;
        for (int i = 0 ; i < n ; i ++ ) {
            if (search(i) >  f) {
                f = search(i);
                best = i;
            }
        }

        std::cout << f << std::endl;
        std::cout << best + 1;
        while (dp[best] > 1) {
            best = bt[best];
            std::cout << " " << best + 1;
        }
        std::cout << std::endl;
    }
}
