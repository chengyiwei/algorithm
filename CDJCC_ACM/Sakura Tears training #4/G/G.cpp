#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("G.in", "r", stdin);
    srand(20040318);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> a(n + 1, 0), b(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            int hsh1 = rand() * rand(), hsh2 = rand() * rand();
            a[u] ^= hsh1; a[v] ^= hsh1;
            b[u] ^= hsh2; b[v] ^= hsh2;
        }
        map<pair<int, int>, int> mp;
        int now1 = 0, ans = 0, now2 = 0;
        for (int i = 1; i <= n; i++) {
            now1 ^= a[i]; now2 ^= b[i];
            mp[{now1, now2}] += 1;
            ans = max(ans, mp[{now1, now2}]);
        }
        cout << n - ans << '\n';
    }
    return 0;
}