#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool> visited;
map<int, vector<int> > w;
int n;

void visit(int k) {
    if (visited[k]) return;
    visited[k] = true;
    for (auto it = w[k].begin(); it != w[k].end(); it++) {
        visit(*it);
    }
}

int main() {
    int a, b;
    cin >> n;
    while (cin >> a >> b) {
        w[a].push_back(b);
    }

    // searching from 1
    visit(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << i << endl;
        }
    }

}
