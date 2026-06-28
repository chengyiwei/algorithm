#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("H.in", "r", stdin);
    freopen ("H0.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    vector<int> up(n), dn(n), le(n), ri(n);
    for (int i = 0; i < k; i++) cin >> le[i] >> dn[i] >> ri[i] >> up[i];
    
    vector<vector<int>> mp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < k; i++) {
        for (int j = le[i]; j <= ri[i]; j++) {
            for (int l = dn[i]; l <= up[i]; l++) {
                mp[j][l] += 1;
            }
        }
    }
    for (int j = m; j >= 1; j--) {
        for (int i = 1; i <= n; i++)
            cout << mp[i][j] << " ";
        cout << '\n';
    }
    return 0;
}