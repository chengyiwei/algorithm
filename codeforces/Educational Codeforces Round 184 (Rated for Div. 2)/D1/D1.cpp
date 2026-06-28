#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 MX = 1e12;

void solve() {
    i64 x, y, k; cin >> x >> y >> k;
    i64 n = x;
    while (n > 0) {
        k = k + (k - 1) / (y - 1);
        if (k > MX) {
            cout << -1 << '\n';
            return ;
        }
        n -= 1;
    }
    cout << k << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}