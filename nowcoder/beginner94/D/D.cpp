#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
int fa[62][MAXN];

int find(int j, int x) {
    return fa[j][x] == x ? x : fa[j][x] = find(j, fa[j][x]);
}

void merge(int j, int x, int y) {
    x = find(j, x), y = find(j, y);
    if (x != y) fa[j][x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen ("D.in", "r", stdin);
    int n, m, q;ll V; cin >> n >> m >> q >> V;
    vector<int> u(m + 1), v(m + 1);
    vector<ll> w(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> u[i] >> v[i] >> w[i];

    for (int j = 0; j <= 61; j++)
        for (int i = 1; i <= n; i++)
            fa[j][i] = i;

    for (int i = 1; i <= m; i++) {
        for (int j = 60; j >= 0; j--) {
            if (((V >> j) & 1) == 0 && ((w[i] >> j) & 1))
                merge (j, u[i], v[i]);
            else if (((V >> j) & 1) && ((w[i] >> j) & 1) == 0)
                break;
        }
        if ((w[i] & V) >= V) merge (61, u[i], v[i]);
    }

    auto query = [&](int u, int v) {
        for (int j = 61; j >= 0; j--) {
            if (find(j, u) == find(j, v)) return true;
        }
        return false;
    };

    while (q--) {
        int u, v; cin >> u >> v;
        cout << (query(u, v) ? "Yes" : "No") << '\n';
    }
    return 0;
}