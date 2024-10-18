#include <bits/stdc++.h>

using i128 = __int128;
using ll = long long;
using ld = long double;

const ld eps = 1e-9;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ld qpow(ld a, ll b) {
    ld res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool cmp(ld a, ld b) {
    return std::abs(a - b) < eps;
}

void solve() {
    ll N, K; std::cin >> N >> K;
    int ans = 0;
    for (ll i = 1; i * i * i <= N; i++) if (N % i == 0) {
        ll c = i; // c = a - b;
        ll d = N;
        for (int j = 1; j <= K; j++) d /= c;
        if (d == 0) break;

        ll L = 0, R = 1e18;
        while (L <= R) {
            ll mid = (R - L) / 2 + L;
            ld a = c + mid, b = mid;
            if (cmp(qpow(a, K) - qpow(b, K) - N, 0)) {
                ans += 1; break;
            }
            if (qpow(a, K) - qpow(b, K) - N > 0) R = mid - 1;
            else L = mid + 1;
        }
    }
    std::cout << ans << '\n';
}

int main() {
    freopen ("I.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}