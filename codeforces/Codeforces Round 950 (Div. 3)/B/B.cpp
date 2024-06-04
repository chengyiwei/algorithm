#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x = a[m];
    int cnt_small = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > x) cnt_small++;
        if (a[i] == x) cnt++;
    }
    if (k == n || cnt_small + cnt <= k)
        cout << "YES" << endl;
    else if (cnt_small >= k)
        cout << "NO" << endl;
    else
        cout << "MAYBE" << endl;
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}