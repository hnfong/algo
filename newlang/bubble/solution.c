#include <stdio.h>
#include <stdlib.h>

int main() {
    int w[9999];  // XXX: this is not enough, but I don't want to implement resizable arrays here.
    char buf[12]; // enough for 32bits integer
    int N = 0;

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        w[N++] = atoi(buf);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j > 0; j--)
            if (w[j] < w[j-1]) {
                int t = w[j];
                w[j] = w[j-1];
                w[j-1] = t;
            }
    }

    for (int i = 0 ; i < N; i++)
        printf("%d\n", w[i]);

    return 0;
}
