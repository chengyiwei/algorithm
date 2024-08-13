#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll inf = 1e15;

int main() {
    freopen ("E.in", "r", stdin);
    int k ,n; cin >> n >> k;
    vector<int> c(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> c[i] >> v[i];
    
    const vector<pll> infv = {{-inf, -1}, {-inf, -2}};
    vector<vector<vector<pll>>> dp(2);  // 三维数组 dp[i][j][col] 表示前 i 个物品中选了 j 个，且最后一个物品的颜色是 col 的最大价值
    dp[0].resize(k + 1, infv); dp[1].resize(k + 1, infv);
    dp[0][0][0].first = dp[0][0][1].first = 0;

    for (int i = 1; i <= n; i++) {
        const int col = c[i], val = v[i];
        auto &cur = dp[i & 1], &pre = dp[(i - 1) & 1];
        for (int j = 0; j <= k; j++)
            cur[j] = infv;
        
        //选了当前物品
        for (int j = 0; j <= k; j++) {
            for (auto &x : pre[j]) {
                const ll preval = x.first, precol = x.second;
                if (precol == col) continue;
                cur[j].push_back({preval + val, col});
                break;
            }
        }
        //没选当前物品
        for (int j = 1; j <= k; j++) {
            for (auto &x : pre[j - 1]) {
                const ll preval = x.first, precol = x.second;
                cur[j].push_back({preval, precol});
            }
        }

        //去重
        for (int j = 0; j <= k; j++) {
            auto &a = cur[j];
            sort(a.begin(), a.end()); reverse(a.begin(), a.end());
            if (a[0].second == a[1].second) {
                ll secval = -inf, seccol = -2;
                for (auto x : a) {
                    if (x.second != a[0].second) {
                        secval = x.first;
                        seccol = x.second;
                        break;
                    }
                }
                a[1] = {secval, seccol};
            }
            a.resize(2);
        }
    }

    ll ans = dp[n & 1][k][0].first;
    cout << (ans < 0 ? -1 : ans) << endl;
    return 0;
}