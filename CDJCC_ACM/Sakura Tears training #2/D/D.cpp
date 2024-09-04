#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<pii>> a(n + 1);

    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        a[i].push_back({x + y, x * y});
        int cnt = 0, sum = 0;
        int x_ = x, y_ = y;
        while (cnt < x + y - 1) {
            if (x_ < y_) { sum += x_; cnt += 1; y_ -= 1;}
            else { sum = sum + y_; cnt += 1; x_ -= 1;}
            a[i].push_back({cnt, sum});
        }
    }

    vector<ll> dp(k + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 0; j--) {
            for (auto [cost, val] : a[i]) {
                if (j - cost >= 0)
                    dp[j] = min(dp[j], dp[j - cost] + val);
            }
        }
    }

    if (dp[k] == INF) cout << -1 << '\n';
    else cout << dp[k] << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}