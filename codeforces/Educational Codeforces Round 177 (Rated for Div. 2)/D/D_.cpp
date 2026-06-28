#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int MAXN = 5e5 + 5;
using ll = long long;
constexpr ll MOD = 998244353;

ll Fac[MAXN], Inv[MAXN];

ll fast_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    Fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        Fac[i] = Fac[i - 1] * i % MOD;
    Inv[MAXN - 1] = fast_pow(Fac[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        Inv[i] = Inv[i + 1] * (i + 1) % MOD;
}


ll F[2][MAXN];

void solve() {
    vector<int> c(27);
    ll sum = 0;
    for (int i = 1; i <= 26; i++)
        cin >> c[i], sum += c[i];
    
    ll pre_sum = 0; // 前 i 的和
    F[0][0] = 1;
    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= sum; j++)
            F[i & 1][j] = 0;

        if (c[i] == 0) {
            for (int j = 0; j <= sum; j++)
                F[i & 1][j] = F[1 - i & 1][j];
            continue;
        }
        pre_sum += c[i];

        for (ll odd_sum = pre_sum; odd_sum >= 0; odd_sum --) {
            ll even_sum = pre_sum - odd_sum;
            if (odd_sum >= c[i]) { // 加到奇数里面
                ll now = F[1 - i & 1][odd_sum - c[i]] * Inv[odd_sum - c[i]] % MOD * Fac[odd_sum] % MOD * Inv[c[i]] % MOD;
                F[i & 1][odd_sum] = (F[i & 1][odd_sum] + now) % MOD;
            }
            if (even_sum >= c[i]) { // 加到偶数里面
                ll now = F[1 - i & 1][odd_sum] * Inv[even_sum - c[i]] % MOD * Fac[even_sum] % MOD * Inv[c[i]] % MOD;
                F[i & 1][odd_sum] = (F[i & 1][odd_sum] + now) % MOD;
            }
        }
    }
    ll ans = 0;
    if (sum % 2 == 0) {
        ans = F[26 & 1][sum / 2];
    }
    else {
        ans = F[26 & 1][sum / 2 + 1];
    }
    cout << ans << '\n';
}

signed main() {
    // freopen ("D.in", "r", stdin);
    init();
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}