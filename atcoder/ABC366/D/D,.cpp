#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    freopen ("D.in" , "r" , stdin);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<vector<int>>> a(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                cin >> a[i][j][k];
            }
    vector<vector<vector<int>>> s(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                s[i][j][k] = s[i - 1][j][k] + s[i][j - 1][k] + s[i][j][k - 1] - s[i - 1][j - 1][k] - s[i - 1][j][k - 1] - s[i][j - 1][k - 1] + s[i - 1][j - 1][k - 1] + a[i][j][k];
            }
    int Q; cin >> Q;
    while (Q--) {
        int x1, y1, z1, x2, y2, z2; cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        cout << s[x2][y2][z2] - s[x1 - 1][y2][z2] - s[x2][y1 - 1][z2] - s[x2][y2][z1 - 1] + s[x1 - 1][y1 - 1][z2] + s[x1 - 1][y2][z1 - 1] + s[x2][y1 - 1][z1 - 1] - s[x1 - 1][y1 - 1][z1 - 1] << endl;
    }
    return 0;
}