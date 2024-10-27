#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = n;
    for (int i = 1; i <= n; i++) {
        int suf = 0;
        for (int j = i + 1; j <= n; j++)
            if (a[j] > a[i]) suf += 1;
        ans = min(ans, suf + i - 1);
    }
    cout << ans << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}