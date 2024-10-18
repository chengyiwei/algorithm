#include <bits/stdc++.h>

using ll = long long;
constexpr ll TT = 1e9 + 9;
constexpr int N = 105;

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
    freopen ("L.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    ll M, K; std::cin >> M >> K;
    ll a = 0, b = 0, cnt = 1, dq_fm = 1;
    for (int i = 1; i <= K; i++) {
        b = (b + a * M + M * dq_fm) % TT;
        a = (a * cnt + a * (M - 1) + M * dq_fm) % TT;
        b = b * (cnt + M - 1) % TT;
        dq_fm = dq_fm * (cnt + M - 1) % TT;
        cnt = cnt + M - 1;
    }
    std::cout << b * qpow(dq_fm, TT - 2) % TT << '\n';
    return 0;
}