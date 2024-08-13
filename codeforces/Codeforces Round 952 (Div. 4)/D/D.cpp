#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> col(n + 1, 0), row(m + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char ch; cin >> ch;
            if (ch == '#')
                col[i] += 1, row[j] += 1;
        }
    int c = distance(col.begin(), max_element(col.begin(), col.end()));
    int r = distance(row.begin(), max_element(row.begin(), row.end()));
    cout << c << ' ' << r << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}