#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mi = a.back();
    vector<int> vis(n, 0);
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > mi) vis[i] = 1;
        mi = min(mi, a[i]);
    }
    mi = INF;
    for (int i = 0; i < n; i++) {
        if (vis[i]) mi = min(mi, a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > mi + 1) vis[i] = 1;
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
        ans[i] = a[i] + vis[i];
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}