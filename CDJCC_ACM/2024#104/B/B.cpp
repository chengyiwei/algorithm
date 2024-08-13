#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, x, a, b; cin >> l >> r >> x >> a >> b;
    map<int, int> mp;
    mp[l] = 1; mp[r] = 1; mp[a - x] = 1; mp[a + x] = 1; mp[b - x] = 1; mp[b + x] = 1;
    mp[a - x + 1] = 1; mp[a + x - 1] = 1; mp[b - x + 1] = 1; mp[b + x - 1] = 1;
    int cnt = 0;
    for (auto &i : mp) i.second = ++cnt;
    vector<int> vis(cnt + 1, 0);
    for (int i = mp[a - x + 1]; i <= mp[a + x - 1]; i++) vis[i] += 1;
    for (int i = mp[b - x + 1]; i <= mp[b + x - 1]; i++) vis[i] += 1;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    if (abs(a - b) >= x) {
        cout << 1 << '\n';
        return;
    }
    int min_x = 1e9;
    for (int i = mp[l]; i <= mp[r]; i++) {
        min_x = min(min_x, vis[i]);
    }
    if (min_x == 0) {
        cout << 2 << '\n';
        return;
    }
    if ((a - x < l && a + x > r) || (b - x < l && b + x > r)) {
        cout << -1 << '\n';
        return ;
    }
    if (1) {
        cout << 3 << '\n';
        return;
    }
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}