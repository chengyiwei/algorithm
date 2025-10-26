#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n <= 600) {
        vector<vector<int>> pre(n, vector<int>(n, 0));
        auto lst = pre;
        for (int i = 0; i < n; i++) {
            int now = a[i];
            pre[i][i] = now;
            for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
                now = now / 2 + a[j];
                pre[i][j] = now;
            }
        }
        for (int i = 0; i < n; i++) {
            int now = a[i];
            lst[i][i] = now;
            for (int j = (i - 1 + n) % n; j != i; j = (j - 1 + n) % n) {
                now = now / 2 + a[j];
                lst[i][j] = now;
            }
        }

        for (int i = 0; i < n; i++) {
            int ansi = a[i];
            for (int j = i; ; j = (j + 1) % n) {
                int nxt_j = (j + 1) % n;
                ansi = max(ansi, lst[j][i] + pre[nxt_j][i] - a[i]);
                if (nxt_j == i) break;
            }
            ans[i] = ansi;
        }
    }
    else {
        vector<int> pre(n, 0), lst(n, 0);
        int tmp = 0;
        for (int i = 0; i <= 30; i++) {
            tmp = tmp / 2 + a[i];
        }
        pre[30] = tmp;
        for (int i = 31; i != 30; i = (i + 1) % n) {
            tmp = tmp / 2 + a[i];
            pre[i] = tmp;
        }

        tmp = 0;
        for (int i = 30; i >= 0; i--) {
            tmp = tmp / 2 + a[i];
        }
        lst[0] = tmp;
        for (int i = n - 1; i != 0; i = (i - 1) % n) {
            tmp = tmp / 2 + a[i];
            lst[i] = tmp;
        }

        // for (int i = 0; i < n; i++)
        //     cout << pre[i] << " ";
        // cout << '\n';

        // for (int i = 0; i < n; i++)
        //     cout << lst[i] << " ";
        // cout << '\n';

        for (int i = 0; i < n; i++) {
            ans[i] = pre[i] + lst[i] - a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    freopen ("F.in", "r", stdin);
    freopen ("F0.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}