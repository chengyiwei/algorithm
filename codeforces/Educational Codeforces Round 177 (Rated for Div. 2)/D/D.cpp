#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1 + 5;
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

        for (int j = 0; j <= sum; j++)
            F[0][j] = F[1][j] = 0;
    
    
    ll pre_sum = 0; // 前 i 的和
    F[0][0] = F[1][0] = 1;
    for (int i = 1; i <= 26; i++) {
        if (c[i] == 0) continue;
        pre_sum += c[i];
        for (ll odd_sum = pre_sum; odd_sum >= 0; odd_sum --) {
            if (odd_sum >= c[i]) { // 加到奇数里面
                ll now = F[1][odd_sum - c[i]] * Inv[odd_sum - c[i]] % MOD * Fac[odd_sum] % MOD * Inv[c[i]] % MOD;
                F[1][odd_sum] = (F[1][odd_sum] + now) % MOD;
            }
        }
        for (ll even_sum = pre_sum; even_sum >= 0; even_sum --) {
            if (even_sum >= c[i]) { // 加到偶数里面
                ll now = F[0][even_sum - c[i]] * Inv[even_sum - c[i]] % MOD * Fac[even_sum] % MOD * Inv[c[i]] % MOD;
                F[0][even_sum] = (F[0][even_sum] + now) % MOD;
            }
        }
    }
    ll ans = 0;
    if (sum % 2 == 0) {
        ans = F[0][sum / 2] * F[1][sum / 2] % MOD;
    }
    else {
        ans = F[1][sum / 2 + 1] * F[0][sum / 2] % MOD;
    }
    cout << ans << '\n';
    for (int i = 0; i <= sum; i++) {
        cout << F[0][i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i <= sum; i++) {
        cout << F[1][i] << ' ';
    }
}

int main() {
    // freopen ("D.in", "r", stdin);
    init();
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}