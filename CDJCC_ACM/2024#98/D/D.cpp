#include <bits/stdc++.h>
using namespace std;
const int maxp = 5005, maxn = 1005;

int dp[2][maxp << 1], n;
int a[maxn], b[maxn];

int main() {
    freopen ("D.in", "r", stdin);
    cin >> n;
    memset(dp, 0x3f, sizeof dp); dp[0][maxp] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++) {
        int d = a[i] - b[i], cur = i & 1, pre = cur ^ 1;
        memset(dp[cur], 0x3f, sizeof (dp[cur]));
        for (int j = -maxp + 1; j < maxp; j++) {
            if (j + maxp + d >= 0 && j + maxp + d < (maxp << 1))
                dp[cur][j + maxp + d] = min(dp[cur][j + maxp + d], dp[pre][j + maxp]);
            if (j + maxp - d >= 0 && j + maxp - d < (maxp << 1))
                dp[cur][j + maxp - d] = min(dp[cur][j + maxp - d], dp[pre][j + maxp] + 1);
        }
    }
    for (int j = 0; j < maxp; j++) {
        int now = min(dp[n & 1][j + maxp], dp[n & 1][-j + maxp]);
        if (now != 0x3f3f3f3f) {
            cout << now << '\n';
            return 0;
        }
    }
    return 0;
}