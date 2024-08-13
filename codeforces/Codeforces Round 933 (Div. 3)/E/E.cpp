#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;

int calc (vector<int> a, int d) {
    int n = a.size() - 1;
    vector<int> f(n + 1, 0);
    deque<pii> q;
    q.push_back({1, a[1] + 1}); f[1] = a[1] + 1;
    for (int i = 2; i <= n; i++) {
        while (q.size() > 0 && q.front().first < i - d) q.pop_front();
        f[i] = q.front().second + a[i] + 1;
        while (q.size() > 0 && q.back().second >= f[i]) q.pop_back();
        q.push_back({i, f[i]});
    }
    return f[n];
}

void solve() {
    int n, m, k, d; cin >> n >> m >> k >> d;
    d = d + 1;
    vector<vector<int> > a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> a[i][j];
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) 
        p[i] = calc(a[i], d);
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        s[i] = s[i - 1] + p[i];
    int ans = 1e18;
    for (int i = k; i <= n; i++) {
        ans = min(ans, s[i] - s[i - k]);
    }
    cout << ans << '\n';
    
}

signed main() {
    freopen ("E.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
}