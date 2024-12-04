#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    long long sum_a = 0, sum_b = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i]) sum_a += a[i];
        else sum_b += b[i];
    }
    long long ans = -1e18;
    for (int i = 0; i < n; i++) {
        long long tmp = sum_a + sum_b;
        if (a[i] >= b[i]) tmp -= a[i];
        else tmp -= b[i];
        tmp += a[i] + b[i];
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
}

int main() {
    freopen ("C.in" , "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}