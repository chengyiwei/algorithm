#include <bits/stdc++.h>
using namespace std;
const int maxn =5005;
typedef long long ll;
ll dp[maxn][maxn][2][2];
int a[maxn];
ll dfs (int pos, int h, int pre2, int pre1) {
    if (h > pos) return 0ll;
    if (h < 0) return 0ll;
    if (dp[pos][h][pre2][pre1] != -1) return dp[pos][h][pre2][pre1];
    ll ret = 0;
    if (pre1 == a[pos]) { // 不改
        ret += dfs(pos - 1, h, 0, 0);
        ret += dfs(pos - 1, h, 1, 0);
        ret += dfs(pos - 1, h, 0, 1);
        if (a[pos]) ret += dfs(pos - 1, h, 1, 1);
    }
    else {
        ret += dfs(pos - 1, h - 1, 0, 0);
        ret += dfs(pos - 1, h - 1, 1, 0);
        ret += dfs(pos - 1, h - 1, 0, 1);
        if (a[pos]) ret += dfs(pos - 1, h - 1, 1, 1);
    }
    return dp[pos][h][pre2][pre1] = ret;
}

int main() {
    freopen ("C.in", "r", stdin);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
    memset(dp, -1, sizeof dp);
    int now;
    dp[0][0][0][0] = 1; dp[0][0][0][1] = 0; dp[0][0][1][0] = 0; dp[0][0][1][1] = 0;
    ll ans = 0;
    for (int j = 0; j <= k; j++) {
        ans += dfs(n, j, 0, 0);
        ans += dfs(n, j, 1, 0);
        ans += dfs(n, j, 0, 1);
        ans += dfs(n, j, 1, 1);
    }
    cout << ans << endl;
    return 0;
}