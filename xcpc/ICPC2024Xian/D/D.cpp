#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int maxn = 1e6;
int main() {
    freopen ("D.in", "r", stdin);
    freopen ("D.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i], sum += b[i];
    map<ll, ll> mp;
    ll ans = INF;
    for (int k = 0; k <= maxn; k++) {
        mp.clear();
        ll cnt = 0;
        for (ll i = 1; (i - 1) * k <= maxn && i <= n; i++) {
            if ((i - 1) * k <= a[i]) {
                mp[a[i] - (i - 1) * k] += b[i];
                cnt = max(cnt, mp[a[i] - (i - 1) * k]);
            }
        }
        ans = min(ans, sum - cnt);
    }
    cout << ans << endl;
    return 0;
}