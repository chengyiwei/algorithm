#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;

ll read() {
    ll x = 0; char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}

ll qp(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}

ll sqrt(ll x) {
    ll l = 0, r = x;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (mid * mid <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

void print(ll x) {
    if (x == 0) return;
    print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    freopen ("F.in", "r", stdin);
    freopen ("F.out", "w", stdout);
    ll n; n = read();
    vector<ll> A;
    for (ll b = 3; b <= min(ll(62), n); b++) {
        for (ll a = 1; ; a++) {
            ll x = qp(a, b);
            if (x <= n) A.push_back(x);
            else break;
        }
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    ll siz2 = sqrt(n);
    for (auto x : A) {
        ll sq = sqrt(x);
        if (sq * sq == x)
            siz2 -= 1;
    }
    ll ans = A.size(); ans += siz2;
    print(ans); putchar('\n');
    return 0;
}