#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    
    vector<int> a(n + 1, 0);
    vector<pair<int, int>> c1, c2;
    for (int i = 1; i <= q; i++) {
        int op, l, r; cin >> op >> l >> r;
        if (op == 1) c1.emplace_back(l, r);
        else c2.emplace_back(l, r);
    }

    for (auto [l, r] : c2) {
        for (int j = l; j <= r; j++) {
            a[j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) if (a[i] != -1) a[i] = k;
    for (auto [l, r] : c1) {
        for (int j = l; j <= r; j++) {
            if (a[j] != k) a[j] = k + 1;
        }
    }
    
    sort(c2.begin(), c2.end(), [](auto &x, auto &y){
        return x.second < y.second;
    });

    for (auto [l, r] : c2) {
        set<int> s;
        for (int j = 0; j < k; j++) s.insert(j);
        for (int j = l; j <= r; j++) {
            if (a[j] != -1) {
                if (s.count(a[j])) s.erase(a[j]);
            }
        }
        for (int j = r; j >= l; j--) {
            if (a[j] == -1 && !s.empty()) {
                a[j] = *s.begin();
                s.erase(s.begin());
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << max(a[i], 0) << " ";
    }
    cout << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}