#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<int> fa(n + 1, 0);
    iota(fa.begin(), fa.end(), 0);

    function<int(int)> find = [&] (int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    };

    auto unite = [&] (int x, int y) {
        x = find(x); y = find(y);
        if (x != y) fa[x] = y;
    };

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<pair<int, int>> ans;

    for (int i = n - 1; i >= 1; i--) {
        vector<int> p(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (find(j) != j) continue;
            int x = a[j] % i;
            if (p[x] == 0) {
                p[x] = j;
            }
            else {
                ans.emplace_back(p[x], j);
                unite(p[x], j);
                break;
            }
        }
    }

    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}