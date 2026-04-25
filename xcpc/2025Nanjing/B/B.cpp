#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    map<long double, int> mp;
    int now = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0) { continue; }
        long double s = atan2l(a, -b); // 必须long double
        long double t = atan2l(-a, b);
        mp[s]++;
        mp[t]--;    
        if (s > t) {
            now++;
        }
    }

    // ishot pro 

    int ans = now;
    for (auto _ : mp) {
        int delta = _.second;
        now += delta;
        ans = max(ans, now);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}