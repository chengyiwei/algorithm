#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
const int maxn = 105;
char mp[maxn][maxn];
int p, q;
int op[maxn], z[maxn];
int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    cin >> p >> q;
    for (int i = 1; i <= q; i++)
        cin >> op[i] >> z[i];
    while (p--) {
        for (int i = 1; i <= q; i++) {
            if (op[i] == 1) {
                int t = z[i];
                char tmp = mp[t][m];
                for (int k = m; k >= 2; k--) {
                    mp[t][k] = mp[t][k - 1];
                }
                mp[t][1] = tmp;
            }
            else {
                int t = z[i];
                char tmp = mp[n][t];
                for (int k = n; k >= 2; k--) {
                    mp[k][t] = mp[k - 1][t];
                }
                mp[1][t] = tmp;
            }
            // for (int i = 1; i <= n; i++)
            //     for (int j = 1; j <= m; j++)
            //         cout << mp[i][j] << " \n"[j == m];
            // cout << endl;
        }
    }
    cout << mp[x][y] << endl;
    return 0;
}