#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> f[i];
    
    long long ans = 0x3f3f3f3f3f3f3f3f;

    for (int i = 1, j; i <= n;) {
        j = i;
        while (j <= n && f[j] == f[i]) j++;
        long long now = 1ll * (i - 1) * f[i] + 1ll * (n - j + 1) * f[i];
        ans = min(ans, now);
        i = j;
    }
    cout << ans << "\n";
}

int main() {
    // freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}