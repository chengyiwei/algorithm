#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    int nn = 0, mm = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'x') cnt += 1;
        }
        if (cnt) nn += 1, mm = max(mm, cnt);
    }
    int g = __gcd(nn, mm);
    nn /= g, mm /= g;
    for (int i = 1; i <= nn; i++) {
        for (int j = 1; j <= mm; j++) {
            cout << 'x';
        }
        cout << '\n';
    }
    return 0;
}