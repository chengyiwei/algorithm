#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef bitset<64> BIT;
void solve () {
    ll n; cin >> n;
    BIT b(n);
    if (b.count() == 1) {
        cout << 1 << '\n' << n << '\n';
        return;
    }
    vector<ll> ans;
    for (int i = 0; i < 64; i++) {
        if (b[i]) {
            BIT c = b;
            c[i] = 0;
            ll now = c.to_ullong();
            ans.push_back(now);
        }
    }
    ans.push_back(n);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << " ";
    cout << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}