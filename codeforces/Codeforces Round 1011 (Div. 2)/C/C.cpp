#include <bits/stdc++.h>
using namespace std;
using ll = long long;   

void solve() {
    ll x, y; cin >> x >> y;
    if (x == y) {
        cout << -1 << '\n';
        return;
    }
    ll k = (1ll << 50) - max(x, y);
    cout << k << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

}