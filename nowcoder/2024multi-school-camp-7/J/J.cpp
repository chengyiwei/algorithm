#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll L, x, y; cin >> L >> x >> y;
    if (x *x + y * y <= L * L) {
        cout << "Yes\n" << 0 << "\n"; 
    }
    else if ((L - x) * (L - x) + y * y <= L * L) {
        cout << "Yes\n" << L << "\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}