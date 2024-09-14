#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("G.in", "w", stdout);
    ios::sync_with_stdio(false);
    int n = 5;
    cout << n << '\n';
    vector<pair<int, int>> edges;
    for (int i = 2; i <= n; i++) {
        int f = rand() % (i - 1) + 1;
        cout << f << ' ' << i << '\n';
        edges.emplace_back(f, i);
    }
    shuffle(edges.begin(), edges.end(), mt19937(chrono::steady_clock::now().time_since_epoch().count()));
    for (auto [u, v] : edges) {
        cout << v << ' ' << u << '\n';
    }
    return 0;
}