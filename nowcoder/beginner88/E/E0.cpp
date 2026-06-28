#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--) {
        int x, y; cin >> x >> y;
        for (int i = 1; i <= n; i++) {
            if (a[i] == x) {
                a[i] = y;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main() {
    freopen ("E.in", "r", stdin);
    freopen ("E0.out", "w", stdout);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}