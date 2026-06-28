#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 10;
typedef long long ll;
int cnt[MAXN];

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1);
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            if (a[i][j] < MAXN) cnt[a[i][j]] = 1;
        }
        int flg = 0;
        for (int j = 0; ; j++) {
            if (cnt[j] == 0) {
                if (flg == 1) {
                    maxn = max(maxn, j);
                    break;
                }
                else flg = 1;
            }
        }
        for (int j = 0; j < k; j++) {
            if (a[i][j] < MAXN)
                cnt[a[i][j]] = 0;
        }
    }

    vector<vector<pair<int,int>>> g(maxn + 1);
    for (int i = 1; i <= n; i++) {
        int k = a[i].size();
        for (int j = 0; j < k; j++) 
            if (a[i][j] < MAXN) cnt[a[i][j]] = 1;
        int flg = -1;
        for (int j = 0; ; j++) {
            if (cnt[j] == 0) {
                if (flg != -1) {
                    g[j].push_back({flg, i}); // i -> j
                    break;
                }
                else flg = j;
            }
        }
        for (int j = 0; j < k; j++) 
            if (a[i][j] < MAXN)
                cnt[a[i][j]] = 0;
    }
    
    vector<int> to(maxn + 1);
    for (int i = 0; i <= maxn; i++) to[i] = i;
    vector<vector<pair<int,int>>> g_(maxn + 1);
    int max_to = 0;
    for (int j = maxn; j >= 0; j--) {
        for (auto [i, id] : g[j]) {
            to[i] = max(to[i], to[j]);
            g_[i].push_back({to[i], id});
            max_to = max(max_to, i);
        }
        if (g_[j].size() >= 2) {
            int now = 0;
            for (auto [val, id] : g_[j])
                now = max(now, val);
            max_to = max(max_to, now);
        }
    }

    ll ans = 0;
    if (m <= maxn) {
        for (int i = 0; i <= m; i++)
            ans += max(max_to, to[i]);
    }
    else {
        for (int i = 0; i <= maxn; i++) 
            ans += max(max_to, to[i]);
        ans += 1ll * (m + maxn + 1) * (m - maxn) / 2;
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    // ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}