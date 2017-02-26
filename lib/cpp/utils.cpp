#include <utility>

template<typename T, size_t rows, size_t cols> void dump(T (&dat)[rows][cols], size_t rowlimit, size_t collimit) {
    for (int i = 0; i < std::min(rows, rowlimit); i++) {
        for (int j = 0 ; j < std::min(cols, collimit); j++) {
            std::cout << dat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
