#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int main() {
    freopen ("I.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(2 * n + 5, 0), len(n + 2), L(n + 2), R(n + 2);
    vector<vector<pii>> g(2 * n + 5);
    for (int i = 1; i <= 2 * n; i++) cin >> a[i + 1]; n += 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (L[a[i]] == 0) L[a[i]] = i;
        else R[a[i]] = i, len[a[i]] = i - L[a[i]] + 1;
    }
    vector<int> id(n + 1); iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) { return len[i] < len[j]; });
    for (int i = 1; i <= 2 * n; i++) g[i].emplace_back(i + 1, -1);

    vector<int> dis(2 * n + 3, -INF); 
    for (int _ = 1; _ <= n; _++) {
        int v = id[_]; fill(dis.begin(), dis.end(), -INF); dis[L[v]] = 0;
        for (int i = L[v]; i <= R[v]; i++) 
            for (auto [to, w] : g[i]) 
                dis[to] = max(dis[to], dis[i] + (w == -1 ? v : w));
        g[L[v]].emplace_back(R[v] + 1, dis[R[v] + 1]);
    }

    cout << dis[2 * n + 1] << '\n';
    return 0;
}