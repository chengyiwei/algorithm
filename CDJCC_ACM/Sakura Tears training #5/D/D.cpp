#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 2) {
        cout << max({2 * abs(a[1] - a[2]), a[1] + a[2]}) << '\n';
        return ;
    }
    if (n == 3) {
        cout << max({3 * a[1], 3 * a[3], 3 * abs(a[1] - a[2]), 3 * abs(a[2] - a[3]), a[1] + a[2] + a[3]}) << '\n';
    }
    else 
        cout << n * (*max_element(a.begin() + 1, a.end())) << '\n';
}

signed main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}