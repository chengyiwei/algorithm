#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[a[i]] += 1;
    int ans = 0;
    int pre = 0;
    for (auto [pos, val] : mp) {
        int left = pre, right = n - pre - val;
        if (abs(left - right) <= k + val)
            ans += 1;
        pre += val;
    }

    // cout << ans << '\n';

    int lst_pos = -1; // 上一次的位置
    pre = 0;
    for (auto [pos, val] : mp) {
        if (lst_pos == -1) {
            lst_pos = pos;
            pre += val;
            continue;
        }
        int left = pre, right = n - pre;
        if (abs(left - right) <= k) {
            ans += pos - lst_pos - 1;
        }
        pre += val;
        lst_pos = pos;
    }
   
    cout << ans << '\n';
}

signed main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}