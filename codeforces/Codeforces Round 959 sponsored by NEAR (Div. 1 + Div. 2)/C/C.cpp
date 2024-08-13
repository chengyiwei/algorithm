#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve() {
    int n; cin >> n; ll X; cin >> X;
    vector<ll> a(n + 1, 0), sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; sum[i] = sum[i - 1] + a[i];
    }
 
    vector<ll> f(n + 3, 0); 
    int L, R = n;
    for (L = n; L >= 1; L--) {
        while (sum[R] - sum[L - 1] > X) R--;
        f[L] = (R - L + 1) + f[R + 2];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += f[i];
    cout << ans << '\n';
}
 
int main() {
    // freopen ("C.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}