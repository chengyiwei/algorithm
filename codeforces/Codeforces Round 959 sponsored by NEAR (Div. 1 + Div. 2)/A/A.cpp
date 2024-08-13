#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        auto b = a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                b[i][j] = a[(i + 1) % n][(j + 1) % m];
            }
        if (a == b) {
            cout << -1 << '\n';
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << b[i][j] << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}