#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector a(n + 1, vector<ll>(m + 1, 0)), sum_0(n + 1, vector<ll>(m + 1, 0)), sum_1(n + 1, vector<ll>(m + 1, 0));
    vector mp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char ch; cin >> ch;
            mp[i][j] = ch - '0';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            sum_0[i][j] = sum_0[i - 1][j] + sum_0[i][j - 1] - sum_0[i - 1][j - 1] + a[i][j] * (mp[i][j] == 0);
            sum_1[i][j] = sum_1[i - 1][j] + sum_1[i][j - 1] - sum_1[i - 1][j - 1] + a[i][j] * (mp[i][j] == 1);
        }
    
    auto get = [&](int x1, int y1, int x2, int y2, int c) {
        if (x1 > x2 || y1 > y2) return 0ll;
        if (c == 0) return sum_0[x2][y2] - sum_0[x1 - 1][y2] - sum_0[x2][y1 - 1] + sum_0[x1 - 1][y1 - 1];
        else return sum_1[x2][y2] - sum_1[x1 - 1][y2] - sum_1[x2][y1 - 1] + sum_1[x1 - 1][y1 - 1];
    };

    ll s_0 = sum_0[n][m], s_1 = sum_1[n][m];
    vector<ll> p;
    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++) {
            ll cur = get(i - k + 1, j - k + 1, i, j, 0) - get(i - k + 1, j - k + 1, i, j, 1);
            p.push_back(abs(cur));
        }
    ll g = p[0];
    for (int i = 1; i < p.size(); i++)
        g = __gcd(g, p[i]);
    ll d = abs(s_0 - s_1);
    if (d % g == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}