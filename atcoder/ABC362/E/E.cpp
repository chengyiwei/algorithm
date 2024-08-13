#include <bits/stdc++.h>
using namespace std;
const int maxn = 998244353;
int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> p;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            p.push_back(a[i] - a[j]);
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    map<int, vector<int>> mp;
    vector<int> ans(n + 1, 0);
    for (auto T : p) {
        fill(dp.begin(), dp.end(), vector<int>(n + 1, 0));
        mp.clear();
        for (int i = 1; i <= n; i++) {
            dp[i][1] = 1;
            for (auto i_ : mp[a[i] - T]) {
                for (int j = 1; j < n; j++) {
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i_][j]) % maxn;
                }
            }
            mp[a[i]].push_back(i);
            for (int j = 2; j <= n; j++)
                ans[j] = (ans[j] + dp[i][j]) % maxn;
        }
    }
    ans[1] = n;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}