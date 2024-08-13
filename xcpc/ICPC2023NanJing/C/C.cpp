#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll P, m; cin >> P >> m;
    ll ans = m  / P;
    for (ll k = m / P; k <= (m + P - 1) / P; k++)
        if (((k * P + 1) ^ (P - 1)) <= m) ans ++;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}