#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    string s; cin >> s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'a') a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
    }

    mp[0] = 0;
    int ans = n, x = a[n];
    for (int i = 1; i <= n; i++) {
        mp[a[i]] = i;
        if (mp.count(a[i] - x)) 
            ans = min(ans, i - mp[a[i] - x]);
    }

    if (ans == n) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}