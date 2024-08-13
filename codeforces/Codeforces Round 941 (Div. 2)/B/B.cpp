#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, m; cin >> n >> m;
    vector<vector<char> > a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            char ch; cin >> ch;
            a[i][j] = ch;
        }
    int max_row = 0, max_col = 0, min_row = n + 1, min_col = m + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'W') {
                max_row = max(max_row, i);
                max_col = max(max_col, j);
                min_row = min(min_row, i);
                min_col = min(min_col, j);
            }
    if (max_row == n && min_row == 1 && max_col == m && min_col == 1) return true;
    max_row = 0, max_col = 0, min_row = n + 1, min_col = m + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 'B') {
                max_row = max(max_row, i);
                max_col = max(max_col, j);
                min_row = min(min_row, i);
                min_col = min(min_col, j);
            }
    if (max_row == n && min_row == 1 && max_col == m && min_col == 1) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
}