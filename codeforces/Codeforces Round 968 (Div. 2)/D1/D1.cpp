#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 10;
typedef long long ll;
int cnt[MAXN];

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1);
    vector<int> to(n + 1);
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
                    to[i] = j;
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
    int max_ = *max_element(to.begin() + 1, to.end());
    ll ans = 0;
    if (max_ >= m) {
        ans = 1ll * max_ * (m + 1);
    }
    else {
        ans = 1ll * max_ * (max_ + 1) + 1ll * (m + max_ + 1) * (m - max_) / 2;
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}