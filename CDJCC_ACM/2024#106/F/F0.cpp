#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll TT = 998244353;

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
    ll N; cin >> N;
    ll cnt = 0, n_ = N;
    while (n_) n_ /= 10, cnt += 1;
    cnt = qpow(10, cnt);
    cout << N % TT * (1 - qpow(cnt, N) + TT) % TT * qpow((1 - cnt + TT) % TT, TT - 2) % TT << '\n';
    return 0;
}