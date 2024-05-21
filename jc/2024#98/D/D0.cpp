#include <bits/stdc++.h>
using namespace std;
const int maxp = 5005, maxn = 1005;

int dp[maxn][maxp << 1], n;
int a[maxn], b[maxn];

int main() {
    cin >> n;
    memset(dp, 0x3f, sizeof dp); dp[0][maxp] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++) {
        int d = a[i] - b[i];
        for (int j = -maxp + 1; j < maxp; j++) {
            if (j + maxp + d >= 0 && j + maxp + d < (maxp << 1))
                dp[i][j + maxp + d] = min(dp[i][j + maxp + d], dp[i - 1][j + maxp]);
            if (j + maxp - d >= 0 && j + maxp - d < (maxp << 1))
                dp[i][j + maxp - d] = min(dp[i][j + maxp - d], dp[i - 1][j + maxp] + 1);
        }
    }
    for (int j = 0; j < maxp; j++) {
        int now = min(dp[n][j + maxp], dp[n][-j + maxp]);
        if (now != 0x3f3f3f3f) {
            cout << now << '\n';
            return 0;
        }
    }
    return 0;
}