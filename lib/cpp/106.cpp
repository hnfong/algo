#include <iostream>
#include <string.h>
#include <assert.h>
/*
https://www.mathsisfun.com/numbers/pythagorean-triples.html

   When m and n are any two positive integers (m < n):

   a = n^2 - m^2
   b = 2nm
   c = n^2 + m^2

   Then a, b, and c form a Pythagorean Triple.

   -----

   For UVA 106, given limit K,

   c > a, c > b
   so just need to check limit of c
*/

bool p[100000001];

#include "math.cpp"

int main() {
    int K;
    while (std::cin >> K) {
        memset(p, 0, sizeof(p));
        int z = 0;
        for (int m = 1; m*m <= K; m++) {
            for (int n = m + 1; n*n + m*m <= K; n++) {
                int a = n*n - m*m;
                int b = 2*m*n;
                int c = n*n + m*m;
                assert(a*a + b*b == c*c);
                assert(a != b);
                assert(c != b);
                assert(c != a);
                p[a] = true;
                p[b] = true;
                p[c] = true;


                if (gcd(a, b) == 1) {
                    z++;
                }
                // std::cout << "=> " << a << " " << b << " " << c << std::endl;

                int d = 1;
                while (c * d <= K) {
                    p[a * d] = true;
                    p[b * d] = true;
                    p[c * d] = true;

                    // std::cout << "=> " << a * d << " " << b * d << " " << c * d << std::endl;
                    d++;
                }
            }
        }

        std::cout << z << " ";
        z = 0;
        for (int i = 1 ; i <= K; i++) {
            if (!p[i]) z++;
        }
        
        std::cout << z << std::endl;
    }
    
    return 0;
}

