#include <bits/stdc++.h>
using namespace std;

const int MAXM = 5e3 + 5;

int cvj[2][MAXM], csvj[2][MAXM];

void update_cvj(int op, int x, int val) {
    x += 1;
    for (int i = x; i < MAXM; i += i & -i) 
        cvj[op][i] = max(cvj[op][i], val);
}

void update_csvj(int op, int x, int val) {
    x += 1;
    for (int i = x; i < MAXM; i += i & -i) 
        csvj[op][i] = max(csvj[op][i], val);
}


int query_cvj(int op, int x) {
    if (x < 0) return -1;
    x += 1;
    int res = 0;
    for (int i = x; i; i -= i & -i) 
        res = max(res, cvj[op][i]);
    return res;
}

int query_csvj(int op, int x) {
    if (x < 0) return -1;
    x += 1;
    int res = 0;
    for (int i = x; i; i -= i & -i) 
        res = max(res, csvj[op][i]);
    return res;
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(cvj, -1, sizeof(cvj));
    memset(csvj, -1, sizeof(csvj));

    int n, m; cin >> n >> m; m = n - m;
    vector<int> v(n + 1), s(n + 1);
    vector<pair<int, int>> p(m + 1); int cnt = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) s[i] = 1;
        s[i] += s[i - 1];
        if (v[i] != 0) p[++cnt] = {v[i], s[i]};
    }

    vector<int> dp(m + 1, -1); dp[0] = 0;
    for (int i = 1; i <= m; i++) {

        int op = p[i].first > 0 ? 1 : 0;
        int vi = abs(p[i].first), si = p[i].second;

        int pre = max(query_cvj(op ^ 1, si - vi), query_csvj(op, si - vi));

        if (pre != -1) {
            dp[i] = pre + 1;
            update_cvj(op, max(vi, 0), dp[i]);
            update_csvj(op, max(si - vi, 0), dp[i]);
        }

        // for (int j = 0; j < i; j++) {
        //     if (dp[j] == -1) continue;
        //     int vi = abs(p[i].first), vj = abs(p[j].first), si = p[i].second, sj = p[j].second;
        //     if (p[j].first * p[i].first < 0) { // 不一样
        //         if (si - vi >= vj) dp[i] = max(dp[i], dp[j] + 1);
        //     }
        //     else {
        //         if (si - vi >= sj - vj) dp[i] = max(dp[i], dp[j] + 1);
        //     }
        // }
    }

    // for (int i = 1; i <= m; i++) cout << dp[i] << ' ';
    // cout << '\n';

    int ans = 0;
    for (int i = 1; i <= m; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}