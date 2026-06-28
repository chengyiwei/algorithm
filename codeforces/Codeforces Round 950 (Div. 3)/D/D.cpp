#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i + 1 <= n; i++) 
        b[i] = __gcd(a[i], a[i + 1]);
    vector<int> pre(n + 1, 0), suf(n + 1, 0);
    pre[0] = 1;
    for (int i = 1; i < n; i++)
        if (b[i - 1] <= b[i]) pre[i] = 1;
        else break;
    b[n] = inf; b[0] = -inf;
    suf[n] = 1;
    for (int i = n - 1; i >= 1; i--)
        if (b[i] <= b[i + 1]) suf[i] = 1;
        else break;
    for (int i = 2; i <= n - 1; i++) {
        int g = __gcd(a[i - 1], a[i + 1]);
        if (g < b[i - 2])
            continue;
        if (g > b[i + 1])
            continue;
        if (pre[i - 2] && suf[i + 1]) {
            cout << "YES" << endl;
            return ;
        }
    }
    if (pre[n - 2] || suf[2]) {
        cout << "YES" << endl;
        return ;
    }
    cout << "NO" << endl;
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) 
        solve();
    return 0;
}