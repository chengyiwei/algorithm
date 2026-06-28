#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 2, -1), pre(n + 1, 1), suf(n + 1, 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) 
        if (a[i] == a[i - 1])
            pre[i] = pre[i - 1] + 1;
        else 
            pre[i] = 1;
    if (pre[n] == n) {cout << -1 << endl; return ;}
    for (int i = n; i >= 1; i--)
        if (a[i] == a[i + 1])
            suf[i] = suf[i + 1] + 1;
        else 
            suf[i] = 1;
    int ans = inf;
    for (int i = 2; i < n; i++) {
        if (a[i - 1] == a[i + 1] && a[i - 1] != a[i])
            ans = min(ans, min(pre[i - 1], suf[i + 1]));
    }
    cout << ans << endl;

}

int main() {
    freopen ("E.in", "r", stdin); 
    int t; cin >> t;
    while (t--) 
        solve();
    return 0;
}