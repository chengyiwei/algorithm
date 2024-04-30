#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    vector<ll> a, b;
    int cnt_0 = 0;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if (x > 0) a.push_back(x);
        if (x < 0) b.push_back(x);
        if (x == 0) cnt_0 ++;
    }
    ll ans = 0;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i += 2) {
        if (i + 1 < a.size())
            ans += a[i] * a[i + 1];
    }
    for (int i = 0; i < b.size(); i += 2) {
        if (i + 1 < b.size())
            ans += b[i] * b[i + 1];
    }
    if (cnt_0 == 0 && a.size() % 2 == 1 && b.size() % 2 == 1) 
        ans += a.back() * b.back();
    cout << ans << '\n';
}

int main() {
    freopen ("A.in" ,"r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}