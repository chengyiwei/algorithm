#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n; ll k; cin >> k;
    map<ll, vector<ll> > mp;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        mp[x % k].push_back(x / k);
    }
    ll ans = 0;
    vector<ll> odd;
    for (auto &[_, v] : mp) {
        sort(v.begin(), v.end());
        if (v.size() & 1) {
            if (odd.empty() && (n & 1)) {odd = v; continue;}
            else {cout << -1 << '\n'; return;}
        }
        for (int i = 0; i < v.size(); i += 2)
            ans += v[i + 1] - v[i];
    }
    ll ans_1 = 0, ans_2 = 0;
    if (!odd.empty() && odd.size() > 1){
        vector<ll> pre(odd.size(), 0), suf(odd.size(), 0);
        for (int i = 1; i < odd.size(); i += 2)
            pre[i] = (i - 2 >= 0 ? pre[i - 2] : 0ll) + odd[i] - odd[i - 1];
        for (int i = odd.size() - 2; i >= 0; i -= 2)
            suf[i] = (i + 2 < odd.size() ? suf[i + 2] : 0ll) + odd[i + 1] - odd[i];
        ans_1 = min(pre[odd.size() - 2], suf[1]);
        for (int i = 2; i + 1 < odd.size(); i += 2)
            ans_1 = min(ans_1, pre[i - 1] + suf[i + 1]);
        ans += ans_1;
    }
    cout << ans << '\n';
}

int main() {
    freopen ("E.in", "r", stdin);
    freopen ("E.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}