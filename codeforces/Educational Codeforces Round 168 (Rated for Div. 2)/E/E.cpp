#include <bits/stdc++.h>
using namespace std;

constexpr int M = 300, B = 1000;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> pre(M, vector<int>(n + 1, 0)); // pre[j][i] 表示前 i 个数中大于 j 的数的个数
    for (int j = 0; j < M; j++)
        for (int i = 1; i <= n; i++) 
            pre[j][i] = pre[j][i - 1] + (a[i] > j); 
    
    vector<vector<pair<int, int>>> ask(n + 1);
    vector<int> ans(q + 1, 0);
    for (int i = 1; i <= q; i++) {
        int id, k; cin >> id >> k;
        ask[k].push_back({id, i});
    }

    for (int k = 1; k <= n; k++) {
        if (ask[k].empty()) continue;
        sort(ask[k].begin(), ask[k].end());

        if (k <= B) {
            int now = 1, cnt = 0, it = 0;
            for (int i = 1; i <= n; i++) {
                while (it < ask[k].size() && ask[k][it].first == i) {
                    ans[ask[k][it].second] = a[i] >= now;
                    ++it;
                }
                if (a[i] >= now && ++cnt == k) ++now, cnt = 0;
            }
        }
        else {
            int pos = 0, now = 0, it = 0;
            while (pos <= n) {
                pos = lower_bound(pre[now].begin(), pre[now].end(), pre[now][pos] + k) - pre[now].begin();
                // 跳到第一个大于 pre[now][pos] + k 的位置
                now += 1;
                while (it < ask[k].size() && ask[k][it].first <= pos) {
                    ans[ask[k][it].second] = a[ask[k][it].first] >= now;
                    ++it;
                }
            }
        }
    }

    for (int i = 1; i <= q; i++) cout << (ans[i] ? "YES" : "NO") << "\n";
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; T = 1;
    while (T--) solve();
    return 0;
}