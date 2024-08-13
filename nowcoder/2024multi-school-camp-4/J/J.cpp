#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 998244353;

const int MAXN = 1e5 + 5;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

ll pw[MAXN];

int main() {
    freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(false);
    ll N, K; cin >> N >> K;
    string s; cin >> s; s = " " + s;
    vector<int> pw2(N + 1, 1), inv2(N + 1, 1);
    for (int i = 1; i <= N; i++) pw2[i] = pw2[i - 1] * 2 % TT;
    for (int i = 1; i <= N; i++) inv2[i] = qpow(pw2[i], TT - 2);
    for (int i = 0; i <= N; i++) pw[i] = qpow(i, K);
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ll cnt = 0, now = 0;
        for (int j = i; j >= 1; j--) {
            if (s[j] == '0') break;
            if (s[j] == '?') cnt += 1;
            now += inv2[cnt] * pw[i - j + 1] % TT;
            now %= TT;
        }
        ans = (ans + now) % TT;
    }
    cout << ans << '\n';
    return 0;
}