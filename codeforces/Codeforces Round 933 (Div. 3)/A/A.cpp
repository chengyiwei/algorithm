#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            ans += a[i] + b[j] <= k;
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}