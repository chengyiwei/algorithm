#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
typedef long long LL;
int main() {
    freopen ("J.in", "r", stdin);
    int n; 
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[l, r] : a)
        cin >> l >> r;
    int L = 1, R = INF;
    vector<vector<int> > v;
    for (auto &[l, r] : a) {
        if (L > r || R < l) {
            v.push_back({L, R});
            L = l; R = r;
        }
        L = max(L, l); R = min(R, r);
    }
    v.push_back({L, R});
    vector<vector<LL> > dp(v.size(), vector<LL> (2,0));
    for (int i = 1; i < v.size(); i ++) {
        dp[i][0] = min(dp[i - 1][0] + abs(v[i][0] - v[i - 1][0]), dp[i - 1][1] + abs(v[i][0] - v[i - 1][1]));
        dp[i][1] = min(dp[i - 1][0] + abs(v[i][1] - v[i - 1][0]), dp[i - 1][1] + abs(v[i][1] - v[i - 1][1]));
    }
    cout << min(dp.back()[0], dp.back()[1]) << endl;
    return 0;
}