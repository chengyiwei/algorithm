#include <bits/stdc++.h>
using namespace std;

const int flg[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 0x3f3f3f3f;
void solve() {
    int n, m; cin >> n >> m;
    vector mp(n + 1, vector(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    
    auto get = [&] (int x, int y) {
        int ret = -inf;
        for (int k = 0; k < 4; k++) {
            int x_ = x + flg[k][0], y_ = y + flg[k][1];
            if (x_ >= 1 && x_ <= n && y_ >= 1 && y_ <= m)
                ret = max(ret, mp[x_][y_]);
        }
        return ret;
    };

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int t = get(i, j);
            if (mp[i][j] > t)
                mp[i][j] = t;
        }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mp[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
}