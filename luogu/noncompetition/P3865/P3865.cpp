#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("P3865.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int> > f(n + 1, vector<int>(20));
    vector<int> lg2(n + 1, 0);
    for (int i = 1; i <= n; i++)
        f[i][0] = a[i];
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i >> 1] + 1;
    for (int j = 1; j < 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    auto query = [&] (int l, int r) {
        int s = lg2[r - l + 1];
        return max(f[l][s], f[r - (1 << s) + 1][s]);
    };
    while (m--) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    return 0;
}