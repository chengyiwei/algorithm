#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 5;
const int M = 65;
const int TT = 998244353;
int dp[2][M][2][2][2];
int sum[2][2][2][2];
int a[MAXN];

void calc_0_9 (int x, int _) {
    for (int j = 0; j < 2; j++) 
    for (int k = 0; k < 2; k++) {
        dp[_ & 1][x][1][j][k] += (sum[1 - _ & 1][0][j][k] - dp[1 - _ & 1][x][0][j][k] + TT) % TT; dp[_ & 1][x][1][j][k] %= TT;
        dp[_ & 1][x][1][j][k] += (sum[1 - _ & 1][1][j][k] - dp[1 - _ & 1][x][1][j][k] + TT) % TT; dp[_ & 1][x][1][j][k] %= TT;
        sum[_ & 1][1][j][k] = (sum[_ & 1][1][j][k] + dp[_ & 1][x][1][j][k]) % TT;
    }
}

void calc_A_Z (int x, int _) {
    for (int i = 0; i < 2; i++) 
    for (int k = 0; k < 2; k++) {
        dp[_ & 1][x][i][1][k] += (sum[1 - _ & 1][i][0][k] - dp[1 - _ & 1][x][i][0][k] + TT) % TT; dp[_ & 1][x][i][1][k] %= TT;
        dp[_ & 1][x][i][1][k] += (sum[1 - _ & 1][i][1][k] - dp[1 - _ & 1][x][i][1][k] + TT) % TT; dp[_ & 1][x][i][1][k] %= TT;
        sum[_ & 1][i][1][k] = (sum[_ & 1][i][1][k] + dp[_ & 1][x][i][1][k]) % TT;
    }
}

void calc_a_z (int x, int _) {
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
        dp[_ & 1][x][i][j][1] += (sum[1 - _ & 1][i][j][0] - dp[1 - _ & 1][x][i][j][0] + TT) % TT; dp[_ & 1][x][i][j][1] %= TT;
        dp[_ & 1][x][i][j][1] += (sum[1 - _ & 1][i][j][1] - dp[1 - _ & 1][x][i][j][1] + TT) % TT; dp[_ & 1][x][i][j][1] %= TT;
        sum[_ & 1][i][j][1] = (sum[_ & 1][i][j][1] + dp[_ & 1][x][i][j][1]) % TT;
    }
}

signed main() {
    freopen ("I.in", "r", stdin);
    freopen ("I.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        char ch; cin >> ch;
        if (ch == '?') a[i] = 64;
        else if (ch >= '0' && ch <= '9') a[i] = ch - '0';
        else if (ch >= 'A' && ch <= 'Z') a[i] = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'z') a[i] = ch - 'a' + 36;
    }
    sum[0][0][0][0] = 1;
    for (int _ = 1; _ <= n; _++) {
        memset(dp[_ & 1], 0, sizeof(dp[_ & 1]));
        memset(sum[_ & 1], 0, sizeof(sum[_ & 1]));
        int x = a[_];
        if (0 <= x && x <= 9) {
            calc_0_9(x, _);
        }
        if (10 <= x && x <= 35) { // A-Z
            calc_A_Z(x, _);
        }
        if (36 <= x && x <= 36 + 25) { // a-z
            calc_a_z(x, _);
            calc_A_Z(x - 26, _);
        }
        if (x == 64) { // ?
            for (int x_ = 0; x_ <= 36 + 25; x_++) {
                if (0 <= x_ && x_ <= 9)
                    calc_0_9(x_, _);
                if (10 <= x_ && x_ <= 35)
                    calc_A_Z(x_, _);
                if (36 <= x_ && x_ <= 36 + 25)
                    calc_a_z(x_, _);
            }
        }
    }
    int ans = sum[n & 1][1][1][1];
    cout << ans << endl;
    return 0;
}