#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;

ll read_int128() {
    ll x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

void print_int128(ll x) {
    if (x == 0) { putchar('0'); return ; }
    string s = "";
    while (x) s += char(x % 10 + '0'), x /= 10;
    reverse(s.begin(), s.end());
    for (char c : s) putchar(c);
    return ;
}

void solve() {
    ll n = read_int128();
    ll X = read_int128(), K = read_int128(); 
    
    auto calc = [&] (ll u, ll k) {
        ll le = u, ri = u;
        for (ll i = 0; i < k; i++) {
            le = (le << 1);
            ri = (ri << 1 | 1);
            if (n < le) return (ll)0;
        }
        if (n >= ri) return (ll)1ll << k;
        return n - le + 1;
    };

    ll ans = calc (X, K);
    while (X != 1 && K) {
        if (K == 1) ans ++;
        if (K > 1) 
            ans += calc(X ^ 1, K - 2);
        X >>= 1;
        K --;
    }
    print_int128(ans); putchar('\n');
    return ;
}

int main() {
    freopen ("E.in", "r", stdin);
    freopen ("E.out", "w", stdout);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}