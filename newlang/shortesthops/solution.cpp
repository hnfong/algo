#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;
map<int, vector<int> > w;
map<int, bool> v;
queue<pair<int,int> > q;  // pair(to, from)
map<int, int> bt;
int n;

void printbt(int k) {
    if (bt.count(k) != 0) {
        printbt(bt[k]);
        cout << " " << k;
    } else {
        cout << k;
    }
}

int main() {
    int a, b;
    cin >> n;
    while (cin >> a >> b) {
        w[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        sort(w[i].begin(), w[i].end());
    }

    // searching from 1
    q.push(make_pair(1, -1));

    while (q.size() != 0) {
        auto p = q.front();
        q.pop();
        int k = p.first;
        int f = p.second;
        if (v[k]) continue;
        if (f != -1) {
            bt[k] = f;
        }
        v[k] = true;
        for (auto it = w[k].begin(); it != w[k].end(); it++) {
            q.push(make_pair(*it, k));
        }
    }

    for (int i = 2; i <= n; i++) {
        if (bt.count(i) == 0) {
            cout << 0 << endl;
        } else {
            printbt(i);
            cout << endl;
        }
    }
}
