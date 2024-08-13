#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;

ll read() {
    ll x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

void print(ll x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
    ll x = read(), y = read();
    if (y <= x) {
        print(x - y);
        return ;
    }
    ll block = sqrt(2.0 * x + 1.5);
    ll num = (y - 1 - x) / block + 1;
    x = x + num * block;
    ll ans = num + (x - y);
    print(ans);

}

int main() {
    freopen ("I.in", "r", stdin);
    // freopen ("I0.out", "w", stdout);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}