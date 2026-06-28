#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;

int pw3[35];

void init() {
    pw3[0] = 1;
    for (int i = 1; i <= 30; i++) {
        pw3[i] = pw3[i - 1] * 3;
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char> > mp(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    vector<array<int, 3> > tow(k);
    for (int i = 0; i < k; i++) {
        auto &[x, y, p] = tow[i];
        cin >> x >> y >> p;
    }

    auto calc = [&](int id, int r) -> int {
        auto &[x, y, p] = tow[id];
        int ret = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (mp[i][j] == '.') continue;
                if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r) {
                    ret += p;
                }
            }
        return ret;
    };

    int top = 0;
    while (pw3[top] <= n * m * 500)
        top++;
    vector<vector<pii> > ok_tow(k);
    for (int i = 0; i < k; i++)
        for (int r = 1; r < top; r++) {
            int d = calc (i, r);
            d -= pw3[r];
            if (d > 0) {
                ok_tow[i].push_back({r, d});
            }
        }

    vector<int> dp(1 << top, 0);
    for (int j = 0; j < k; j++) { // 枚举位置
        for (int S = (1 << top) - 1; S >= 1; S--) { //枚举状态
            for (auto [x, d] : ok_tow[j]) { //枚举用那个r
                if (! (S >> x & 1)) continue;
                dp[S] = max(dp[S], dp[S ^ (1 << x)] + d);
            }
        }
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
}

signed main() {
    freopen("H.in", "r", stdin);
    init();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}