#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int f[maxn][maxn];

void solve(){
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        f[0][i] = i == k - 1;
    }
    for (int i = 1; i <= m; i++) {
        int x; char ch;
        cin >> x >> ch;
        for (int j = 0; j < n; j++) f[i][j] = 0;
        for (int j = 0; j < n; j++) {
            if (ch != '1') 
                f[i][(j + x) % n] |= f[i - 1][j];
            if (ch != '0') 
                f[i][(j + n - x) % n] |= f[i - 1][j];
        }
    }
    int ans = 0;
    for (int j = 0; j < n; j++) 
        if (f[m][j]) ans++;
    cout << ans << '\n';
    for (int j = 0; j < n; j++) 
        if (f[m][j]) cout << j + 1 << ' ';
    cout << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
}