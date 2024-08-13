#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int flg[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
const int maxn = 1e6 + 5;
int dp[maxn], vis[maxn];
typedef pair<pair<int, int>, pair<int, int>> piiii;
piiii q[maxn];
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 0; i <= n * m * n * m; i++) dp[i] = -1, vis[i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    auto hsh = [&] (int x1, int y1, int x2, int y2) -> int {
        return (x1 - 1) * m * n * m + (y1 - 1) * n * m + (x2 - 1) * m + (y2 - 1);
    };
    
    function<bool(int, int, int, int, int&, int& )> check = [&](int x1, int y1, int x2, int y2, int &hed, int &til) -> bool {
        hed = 1, til = 0;
        q[++til] = {{x1, y1}, {x2, y2}}; vis[hsh(x1, y1, x2, y2)] = 1;
        while (hed <= til) {
            auto [p1, p2] = q[hed++];
            auto [x_1, y_1] = p1; auto [x_2, y_2] = p2;
            for (int k = 0; k < 4; k++) {
                int nx_1 = x_1 + flg[k][0], ny_1 = y_1 + flg[k][1];
                if (nx_1 < 1 || nx_1 > n || ny_1 < 1 || ny_1 > m || a[nx_1][ny_1] == 'O') continue;
                int nx_2 = x_2 + flg[k][0], ny_2 = y_2 + flg[k][1];
                if (nx_2 < 1 || nx_2 > n || ny_2 < 1 || ny_2 > m || a[nx_2][ny_2] == 'O') return true;
                int h_ = hsh(nx_1, ny_1, nx_2, ny_2);
                if (dp[h_] == 1) return true;
                if (vis[h_]) continue; vis[h_] = 1;
                q[++til] = {{nx_1, ny_1}, {nx_2, ny_2}};
            }
        }
        return false;
    };

    int ans = 0;
    for (int x1 = 1; x1 <= n; x1++)
        for (int y1 = 1; y1 <= m; y1++) if (a[x1][y1] == '.') {
            bool now = 1;
            for (int x2 = 1; x2 <= n; x2++)
                for (int y2 = 1; y2 <= m; y2++) {
                    if (a[x2][y2] == 'O') continue;
                    if (x1 == x2 && y1 == y2) continue;
                    int hed, til;
                    int h_ = hsh(x1, y1, x2, y2);
                    if (dp[h_] != -1) { now &= dp[h_]; continue; }
                    bool ok = check(x1, y1, x2, y2, hed, til);
                    for (int i = 1; i <= til; i++) {
                        auto [p1, p2] = q[i];
                        dp[hsh(p1.first, p1.second, p2.first, p2.second)] = ok;
                    }
                    now &= ok;
                }
            ans += now;
        }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    // cout << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    return 0;
}