#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    LL ans = INF, suf = 0;
    for (int i = m; i; i--) {
        ans = min (ans, suf + a[i]);
        suf += b[i];
    }
    for (int i = m + 1; i <= n; i++) 
        ans += min(a[i],b[i]);
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}