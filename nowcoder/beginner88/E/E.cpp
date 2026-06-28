#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);

    map<int,int> mp, fa, cur;

    function<int(int)> find = [&](int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    };

    for (int i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]] = 1, fa[a[i]] = a[i], cur[a[i]] = a[i];
    
    while (m--) {
        int x, y; cin >> x >> y; // 存在必是祖先
        if (mp.count(x) == 0) continue;
        if (mp.count(y) == 0) {
            int fx = find(x);
            cur[fx] = y;
            fa[y] = fx;
        }
        else {
            int fx = find(x), fy = find(y);
            fa[fx] = fy;
        }
        mp.erase(x);
        mp[y] = 1;
    }

    for (int i = 1; i <= n; i++) {
        int x = find(a[i]);
        cout << cur[x] << " \n"[i == n];
    }

}

int main() {
    freopen ("E.in", "r", stdin);
    freopen ("E.out", "w", stdout);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}