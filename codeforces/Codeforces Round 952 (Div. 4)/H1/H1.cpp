#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char> > p(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> p[i][j];

    auto calc = [&] (vector<vector<char> > &a) {
        vector<int> fa(n * m + 1, 0), siz(n * m + 1, 1);
        iota(fa.begin(), fa.end(), 0);
        function<int(int)> find = [&] (int x) {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        };
        function<void(int, int)> unite = [&] (int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            fa[x] = y;
            siz[y] += siz[x];
        };
        function<int(int, int)> id = [&] (int x, int y) {
            return x * m + y;
        };
        vector<int> up (n + 1, 0);
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp.clear();
            if (i > 0) {
                for (int j = 0; j < m; j++) {
                    if (a[i - 1][j] == '#')
                        mp[find(id(i - 1, j))] = siz[find(id(i - 1, j))];
                }
                for (auto &[_, v]: mp) up[i] += v;
            }
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') continue;
                if (i > 0 && a[i - 1][j] == '#') unite(id(i, j), id(i - 1, j));
                if (j > 0 && a[i][j - 1] == '#') unite(id(i, j), id(i, j - 1));
            }
        }
        iota(fa.begin(), fa.end(), 0); fill(siz.begin(), siz.end(), 1);
        vector<int> dn (n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            mp.clear();
            if (i < n - 1) {
                for (int j = 0; j < m; j++) {
                    if (a[i + 1][j] == '#')
                        mp[find(id(i + 1, j))] = siz[find(id(i + 1, j))];
                }
                for (auto &[_, v]: mp) dn[i] += v;
            }
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') continue;
                if (i < n - 1 && a[i + 1][j] == '#') unite(id(i, j), id(i + 1, j));
                if (j > 0 && a[i][j - 1] == '#') unite(id(i, j), id(i, j - 1));
            }
        }

        int ret = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            if (i > 0) cur += up[i];
            if (i < n - 1) cur += dn[i];
            ret = max(ret, cur);
        }
        return ret + m;
    };

    int ans1 = calc(p);
    vector<vector<char> > q(m, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            q[j][i] = p[i][j];
    swap(n, m);
    int ans2 = calc(q);
    int ans = max(ans1, ans2);
    cout << ans << '\n';
}

int main() {
    freopen ("H1.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}