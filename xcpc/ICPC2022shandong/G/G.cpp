#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    vector<pll> p;
    for (int i = 0; i < n; i++)
        cin >> a[i], p.push_back({a[i] - i, a[i]});
    sort(p.begin(), p.end());
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i > 0 && p[i].first == p[i - 1].first) {
            ans += max(p[i].second + p[i - 1].second, 0ll);
            i --;
        }
    }
    cout << ans << endl;
}

int main() {
    freopen ("G.in", "r",stdin);
	ios::sync_with_stdio(false);
    cin.tie(0); 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}