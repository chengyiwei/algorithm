#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll TT = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

int main() {
    freopen ("F.in", "r", stdin);
    int n, m; cin >> m >> n;

    vector<ll> Fac(m + 1, 1), Inv(m + 1, 1);
    for (int i = 1; i <= m; i++) Fac[i] = Fac[i - 1] * i % TT;
    Inv[m] = qpow(Fac[m], TT - 2);
    for (int i = m - 1; i >= 0; i--) Inv[i] = Inv[i + 1] * (i + 1) % TT;

    auto C = [&] (int a, int b) -> ll {
        if (a < b) return 0ll;
        return Fac[a] * Inv[b] % TT * Inv[a - b] % TT;
    };

    ll ans = 0, all = C(m, n) * n % TT;
    
    vector dp(21, vector<ll>(m + 1, 0)); // dp[c][x] 表示长度为 c 的序列，最后一个是 x 的方案数

    vector<vector<int>> prime(m + 1);
    for (int i = 1; i <= m; i++)
        for (int j = i * 2; j <= m; j += i) 
            prime[j].push_back(i);
    
    for (int i = 1; i <= m; i++) dp[1][i] = 1;
    for (int c = 2; c <= 20; c++) {
        for (int x = 1; x <= m; x++) {
            for (auto y : prime[x]) {
                dp[c][x] = (dp[c][x] + dp[c - 1][y]) % TT;
            }
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= min(n, 20); j++) {
            ll now = dp[j][i] * C(m / i - 1, n - j) % TT;
            ans = (ans + now) % TT;
        }
    }

    cout << ((all - ans) % TT + TT) % TT << endl;
    return 0;
}