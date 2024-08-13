#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("E.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
    vector<int> f(n + 1, 0), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x; cin >> x;
            g[i][j] = x;
        }
    }
    int ans = -1, ans_i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (g[j][i] == 1 && f[j] > f[i]) {
                f[i] = f[j];
                pre[i] = j;
            }
        }
        f[i] += a[i];
        if (f[i] > ans) {
            ans = f[i];
            ans_i = i;
        }
    }

    auto print = [&](auto && print, int x) -> void {
        if (pre[x] == 0) {
            cout << x << " ";
            return;
        }
        print(print, pre[x]);
        cout << x << " ";
    };

    print(print, ans_i);
    cout << endl;
    cout << ans << endl;
    return 0;
}