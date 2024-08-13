#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

ll inv(ll x) {
    return qpow(x, TT - 2);
}

int main() {
    freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(false);
    ll N, K; cin >> N >> K;
    string s; cin >> s; s = " " + s;
    vector<int> pw2(N + 1, 1);
    for (int i = 1; i <= N; i++) pw2[i] = pw2[i - 1] * 2 % TT;
    vector<ll> dp(N + 1, 0);
    ll ans = 0;

    auto calc = [&] (int l, int r) {
        string t;
        for (int i = l; i <= r; i++) t += s[i];
        int n = t.size(); t = " " + t;
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (t[i] == '?');
        ll pre = 1, res1 = 0, res2 = 0;
        for (int i = 1; i <= n; i++) {
            ll pi = i * inv(pw2[sum[i]]);
            res1 += pi * pre % TT; res1 %= TT;
            pre = (pre + pw2[sum[i]]) % TT;
        }

        pre = 0;
        for (int i = 1; i <= n; i++) {
            res2 += pre * inv(pw2[sum[i]]) % TT; res2 %= TT;
            ll pj = i * pw2[sum[i]] % TT;
            pre = (pre + pj) % TT;
        }

        ll res = ((res1 - res2) % TT + TT) % TT;
        return res;
    };

    for (int l = 1; l <= N; l++) {
        int r = l;
        while (r <= N && s[r] != '0') r += 1;
        ans += calc(l, r - 1);
    }
    cout << ans << '\n';
    return 0;
}