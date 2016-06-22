#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int M = 10;
const string SPACER = "";
int outsize = 39;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string w[M];
        vector<int> o;
        for (int i = 0 ; i < M; i ++ ) {
            cin >> w[i];
        }

        int k = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0 ; j < M; j++) {
                if (i == j) continue;
                if (w[i][3] == w[j][0]) k = 1;

                if (w[i][2] == w[j][0] && w[i][3] == w[j][1]) k = 2;
                
                if (w[i][1]==w[j][0] && w[i][2]==w[j][1] && w[i][3]==w[j][2]) k = 3;
                
                if (w[i] == w[j]) k = 4;

                if (k > 0) {
                    o.push_back(i);
                    o.push_back(j);
                    goto hell;
                }
            }
        }
        hell:

        if (k > 0) {

        for (int i = 0 ; i < M; i++ ){
            if (i != o[0] && i != o[1]) {
                // cout << i << endl;
                o.push_back(i);
            }
        }
        } else {
            for (int i = 0 ; i < M; i++) {
                o.push_back(i);
            }
        }

        int z = 0;

        cout << w[o[0]] << SPACER; z += 4;
        cout << w[o[1]].substr(k,4) << SPACER; z += 4 - k;

        for (int i = 2; i < M; i++ ){
            cout << w[o[i]] << SPACER; z += 4;
        }

        while (z < outsize) {
            z++;
            cout << "Z";
        }

        cout << endl;
    }
    return 0;
}
