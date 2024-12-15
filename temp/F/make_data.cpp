#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("F.in", "w", stdout);
    srand(time(0));
    int n = 100, m = min(500, n * (n - 1) / 2);
    int k = rand() % n + 1;

    vector<pair<pair<int, int>, int>> edges;

    vector<int> a(n + 1);

    map<pair<int, int>, int> mp;

    for (int i = 1; i <= n; i++) a[i] = rand() % 4 + 1;

    for (int i = 1; i <= n; i++) {
        int u = i, v = rand() % n + 1, w = rand() % 10 + 1;
        while (u == v || mp.count({u, v})) {
            v = rand() % n + 1;
        }
        mp[{u, v}] = mp[{v, u}] = 1;
        edges.push_back({{u, v}, w});
    }

    for (int i = edges.size(); i < m; i++) {
        int u = rand() % n + 1, v = rand() % n + 1, w = rand() % 10 + 1;
        while (u == v || mp.count({u, v})) {
            v = rand() % n + 1;
        }
        mp[{u, v}] = mp[{v, u}] = 1;
        edges.push_back({{u, v}, w});
    }

    vector<int> vis(n + 1, 0);
    vector<int> b;
    for (int i = 1; i <= k; i++) {
        int x = rand() % n + 1;
        if (vis[x]) {
            i--;
            continue;
        }
        vis[x] = 1;
        b.push_back(x);
    }
    assert(b.size() == k);

    cout << n << " " << m << " " << k << '\n';

    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];

    for (auto [x, w] : edges) {
        if (rand() % 2) cout << x.first << " " << x.second << " " << w << '\n';
        else cout << x.second << " " << x.first << " " << w << '\n';
    }

    for (int i = 0; i < k; i++) cout << b[i] << " \n"[i == k - 1];

    return 0;
}