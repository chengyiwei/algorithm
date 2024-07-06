#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 5;
vector<int> factors[maxn];
void init() {
    for (int i = 1; i < maxn; i++)
        for (int j = i; j < maxn; j += i)
            factors[j].push_back(i);
}

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> inva(n + 1, vector<int>()), invb(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        int g = __gcd(p[i], i);
        a[i] = p[i] / g, b[i] = i / g;
        inva[a[i]].push_back(i);
        invb[b[i]].push_back(i);
    }
    ll ans = 0;
        
    vector<int> bj(n + 1, 0);
    for (int x = 1; x <= n; x++) {
        for (int y = x; y <= n; y += x)
            for (auto j : inva[y])
                bj[b[j]] += 1;
        for (auto i : invb[x]) {
            for (auto fac : factors[a[i]])
                ans += 1ll * bj[fac];
        }
        for (int y = x; y <= n; y += x)
            for (auto j : inva[y])
                bj[b[j]] -= 1;
    }
    for (int i = 1; i <= n; i++) 
        if (1ll * p[i] * p[i] % (1ll * i * i) == 0) ans -= 1;
    cout << ans / 2 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    init();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}