#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll sum = 0; ll n = 0; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) { ll x; cin >> x; sum += x; }
    for (ll i = 30; i >= 0; i--) {
        if (((1ll << i) - 1) * n >= sum) continue;
        ll num = min(1ll * n, sum / (1ll << i));
        if (num == 0) continue;
        sum -= num * (1ll << i);
        ans |= 1ll <<  i;
    }
    cout << ans << '\n';
    return 0;
}