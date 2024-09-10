#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("L.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1,vector<char>(m + 1));
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int cnt = 0;
    for (int i= 1; i + 1 <= n; i++)
        for (int j = 1; j + 1 <= m; j++) {
            if (a[i][j] == 'c' && a[i][j + 1] == 'c' && a[i + 1][j] == 'p' && a[i + 1][j + 1] == 'c')
                cnt += 1;
        }
    cout << cnt << endl;
    return 0;
}