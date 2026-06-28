#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    vector<vector<string>> b(m + 1, vector<string>(n + 1));

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; i ++) {
        int flg = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j][i]) {
                flg = 1;
                break;
            }
        }
        if (flg == 0) { // 无解
            cout << "-1\n";
            return;
        }
    }

    int min_miss = INF;
    for (int j = 1; j <= m; j++) {
        int miss = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[j][i]) {
                miss++;
            }
        }
        min_miss = min(min_miss, miss);
    }
    cout << n + 2 * min_miss << '\n';
    return ;
}

int main() {
    freopen ("F.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}