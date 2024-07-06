#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    while (true) {
        if (x == 1) break;
        int d = y - x % y;
        int g = min(k, d);
        x += g;
        k -= g;
        while (x % y == 0) x /= y;
        if (k == 0) break;
    }
    if (k) 
        cout << x + k << '\n';
    cout << x << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}