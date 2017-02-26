#include <iostream>

int main() {
    int B[3];
    int G[3];
    int C[3];
    while (std::cin >> B[0] >> G[0] >> C[0] >> B[1] >> G[1] >> C[1] >> B[2] >> G[2] >> C[2]) {
        // BCG,BGC,CBG,CGB,GBC,GCB
        size_t total = B[0]+B[1]+B[2]+G[0]+G[1]+G[2]+C[0]+C[1]+C[2];
        size_t e = 1ULL << 62;
        std::string cfg = "";
        size_t cur;

        // BCG
        cur = total - B[0] - C[1] - G[2];
        if (cur < e) {
            cfg = "BCG";
            e = cur;
        }

        // BGC
        cur = total - B[0] - C[2] - G[1];
        if (cur < e) {
            cfg = "BGC";
            e = cur;
        }

        // CBG
        cur = total - B[1] - C[0] - G[2];
        if (cur < e) {
            cfg = "CBG";
            e = cur;
        }

        // CGB
        cur = total - B[2] - C[0] - G[1];
        if (cur < e) {
            cfg = "CGB";
            e = cur;
        }

        // GBC
        cur = total - B[1] - C[2] - G[0];
        if (cur < e) {
            cfg = "GBC";
            e = cur;
        }

        // GCB
        cur = total - B[2] - C[1] - G[0];
        if (cur < e) {
            cfg = "GCB";
            e = cur;
        }

        std::cout << cfg << " " << e << std::endl;
    }
}
