#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
typedef pair<int, int> pii;
const int TT = 998244353;

int dp[MAXN][MAXN][1 << 10];

struct Node {
    pii A;
    vector<pii> B;
    Node () {B.resize(2);}
}flg[4];

int d[2][2] = {{1, 0}, {0, 1}};
vector<vector<int>> vis1[1 << 10], vis2[1 << 10];

int main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);

    flg[0].A = {0, -1}; flg[0].B[0] = {-1, -2}; flg[0].B[1] = {1, -2};
    flg[1].A = {0, 1}; flg[1].B[0] = {-1, 2}; flg[1].B[1] = {1, 2};
    flg[2].A = {-1, 0}; flg[2].B[0] = {-2, -1}; flg[2].B[1] = {-2, 1};
    flg[3].A = {1, 0}; flg[3].B[0] = {2, -1}; flg[3].B[1] = {2, 1};

    int n, m; cin >> n >> m;
    vector<pii> a(m);
    for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;

    for (int S = 0; S < (1 << m); S++) {
        vis1[S].assign(n + 1, vector<int>(n + 1, 0)); vis2[S].assign(n + 1, vector<int>(n + 1, 0));
        for (int k = 0; k < m; k++) if (S >> k & 1) vis1[S][a[k].first][a[k].second] = k + 1;
        for (int k = 0; k < m; k++) if (S >> k & 1) {
            for (int l = 0; l < 4; l++) {
                auto [x, y] = a[k];
                int nx = x + flg[l].A.first, ny = y + flg[l].A.second;
                if (nx < 0 || nx > n || ny < 0 || ny > n || vis1[S][nx][ny] != 0) continue;
                int nx1 = x + flg[l].B[0].first, ny1 = y + flg[l].B[0].second;
                if (nx1 >= 0 && nx1 <= n && ny1 >= 0 && ny1 <= n) vis2[S][nx1][ny1] = 1;
                int nx2 = x + flg[l].B[1].first, ny2 = y + flg[l].B[1].second;
                if (nx2 >= 0 && nx2 <= n && ny2 >= 0 && ny2 <= n) vis2[S][nx2][ny2] = 1;
            }
        }
    }

    if (vis2[(1 << m) - 1][0][0] == 1) {cout << 0 << endl; return 0;}

    dp[0][0][(1 << m) - 1] = 1;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            for (int S = 0; S < (1 << m); S++) {
                if (dp[i][j][S] == 0) continue;
                for (int k = 0; k < 2; k++) {
                    int nx = i + d[k][0], ny = j + d[k][1];
                    if (nx > n || ny > n || vis2[S][nx][ny] == 1) continue;
                    int S_ = S;
                    if (vis1[S][nx][ny] != 0) S_ ^= (1 << (vis1[S][nx][ny] - 1));
                    dp[nx][ny][S_] = (dp[nx][ny][S_] + dp[i][j][S]) % TT;
                }
            }
        }
    int ans = 0;
    for (int S = 0; S < (1 << m); S++) ans = (ans + dp[n][n][S]) % TT;
    cout << ans % TT << endl;
    return 0;
}