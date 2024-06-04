#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m, 0));
    vector<int> row(n * m + 1), col(n * m + 1);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> a[i][j], row[a[i][j]] = i, col[a[i][j]] = j;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> b[i][j];
    for (int i = 0; i < n; i++) {
        int r = row[b[i][0]];
        for (int j = 0; j < m; j++) {
            if (row[b[i][j]] != r) {
                cout << "NO" << endl;
                return ;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int c = col[b[0][j]];
        for (int i = 0; i < n; i++) {
            if (col[b[i][j]] != c) {
                cout << "NO" << endl;
                return ;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}