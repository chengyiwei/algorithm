#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 2, 0);
    iota(a.begin(), a.end(), 0);

    function<int(int)> find = [&] (int x) -> int {
        return a[x] == x ? x : a[x] = find(a[x]);
    };

    function<void(int, int)> merge = [&] (int x, int y) {
        if (find(x) == find(y)) return;
        a[find(x)] = find(y);
    };

    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;

    for (int i = 1; i <= n; i++) {
        auto [l, r] = p[i];
        if (find(l) == find(r + 1)) {
            cout << "0\n";
            return;
        }
        merge(l, r + 1);
    }
    set<int> st;
    for (int i = 1; i <= n + 1;  i++) st.insert(find(i));

    if (st.size() == 1) cout << "1\n";
    else cout << "0\n";
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}