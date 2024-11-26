#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, du;
    bool operator < (const Node B) const {
        return val > B.val || (val == B.val && du > B.du);
    }
};

int main() {
    // freopen ("E.in", "r", stdin);
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];

    if (n == 1) {
        cout << a[1] << '\n';
        return 0;
    }

    vector<int> du(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        du[u] ++ , du[v] ++;
    }
    vector<Node> p(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i].du = du[i]; p[i].val = a[i];
    }
    sort(p.begin() + 1, p.end());
    if (p[1].du >= 2) {
        cout << p[1].val << '\n';
    }
    else {
        cout << p[2].val << '\n';
    }
    return 0;
}