#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void solve() {
    LL a, b, m; cin >> a >> b >> m;
    LL ans = 0;
    auto calc =  [&] (LL x) {
        return ((m + x) / x);
    };
    ans += calc(a) + calc(b);
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}