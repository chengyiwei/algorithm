#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check (ll x, ll y) {
    if (x % 2 == 0 && y % 2 == 0) return 0;
    if (x % 2 == 1 && y % 2 == 1) return 0;
    return 1;
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    ll Sx, Sy, Tx, Ty; cin >> Sx >> Sy >> Tx >> Ty;
    if (Sx < Tx) { swap(Sx, Tx); swap(Sy, Ty); }
    ll dy = abs(Ty - Sy);
    ll pos_x = Sx - dy;
    if (check(Sx, Sy) == 1) pos_x -= 1;
    if (check(Tx, Ty) == 1) Tx -= 1;
    ll dx = max(0ll, (pos_x - Tx) / 2);
    cout << dx + dy << endl;
    return 0;
}