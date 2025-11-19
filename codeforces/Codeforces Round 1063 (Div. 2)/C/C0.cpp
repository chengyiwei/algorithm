#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;

void solve() {
    int n; cin >> n;
    array<vector<int>, 2> a = {vector<int>(n + 2), vector<int>(n + 2)};
    for (int i = 1; i <= n; i++) cin >> a[0][i];
    for (int i = 1; i <= n; i++) cin >> a[1][i];

    array<vector<int>, 2> pre_min = {vector<int>(n + 2, INF), vector<int>(n + 2, INF)};
    array<vector<int>, 2> pre_max = {vector<int>(n + 2, -INF), vector<int>(n + 2, -INF)};
    array<vector<int>, 2> suf_min = {vector<int>(n + 2, INF), vector<int>(n + 2, INF)};
    array<vector<int>, 2> suf_max = {vector<int>(n + 2, -INF), vector<int>(n + 2, -INF)};
    
    pre_min[0][n + 1] = -INF; suf_min[0][0] = -INF;

    for (int i = 1; i <= n; i++) {
        pre_min[0][i] = min(pre_min[0][i - 1], a[0][i]); // 前缀最小值
        pre_max[0][i] = max(pre_max[0][i - 1], a[0][i]); // 前缀最大值
        pre_min[1][i] = min(pre_min[1][i - 1], a[1][i]); 
        pre_max[1][i] = max(pre_max[1][i - 1], a[1][i]);
    }
    for (int i = n; i >= 1; i--) {
        suf_min[0][i] = min(suf_min[0][i + 1], a[0][i]); // 后缀最小值
        suf_max[0][i] = max(suf_max[0][i + 1], a[0][i]); // 后缀最大值
        suf_min[1][i] = min(suf_min[1][i + 1], a[1][i]);
        suf_max[1][i] = max(suf_max[1][i + 1], a[1][i]);
    }

    int pos0_pre_max = 0, pos1_suf_max = n + 1;

    auto check = [&] (int mi) {
        int pos0_pre_min = upper_bound(pre_min[0].begin(), pre_min[0].end(), mi, greater<int>()) - pre_min[0].begin() - 1; // 第一个小于 mi 的位置
        if (pre_min[0][1] < mi) pos0_pre_min = 0;
        int pos1_suf_min = lower_bound(suf_min[1].begin(), suf_min[1].end(), mi) - suf_min[1].begin(); // 第一个大于等于 mi 的位置
        if (suf_min[1][n] < mi) pos1_suf_min = n + 1;

        int pre = min(pos0_pre_min, pos0_pre_max);
        int suf = max(pos1_suf_min, pos1_suf_max);
        // pre -= 1; suf += 1;
        return pre >= suf;
    };

    ll ans = 0;

    for (int i = 1; i <= 2 * n; i++) {
        while (pos0_pre_max + 1 <= n && pre_max[0][pos0_pre_max + 1] <= i) 
            pos0_pre_max++;
        while (pos1_suf_max - 1 >= 1 && suf_max[1][pos1_suf_max - 1] <= i) 
            pos1_suf_max--;

        int l = 0, r = i + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (check(mid)) l = mid;
            else r = mid;
        }
        // cout << "r = " << i << ", l = " << l << "\n";
        ans += l;
    }

    cout << ans << "\n";
}

int main() {
    // freopen ("C.in", "r", stdin);
    // freopen ("C0.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)  solve();
}