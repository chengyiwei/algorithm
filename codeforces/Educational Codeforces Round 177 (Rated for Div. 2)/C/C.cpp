#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> fa(n + 1), siz(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fa[i] = i; siz[i] = 1;
    }

    function<int(int)> find = [&](int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    };

    function<void(int, int)> merge = [&](int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return;
        if (siz[fx] < siz[fy]) swap(fx, fy);
        fa[fy] = fx;
        siz[fx] += siz[fy];
        siz[fy] = 0;
    };

    for (int i = 1; i <= n; i++) {
        merge(i, a[i]);
    }

    int ans = 0;
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int fx = find(x);
        if (b[fx] == 0) {
            ans += siz[fx];
            b[fx] = 1;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}