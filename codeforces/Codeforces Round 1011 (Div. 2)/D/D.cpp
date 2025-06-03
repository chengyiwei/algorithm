#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> vis(n + 1, 0);
    for (int i = n - k; i >= 1; i -= k + 1) vis[i] = 1;
    priority_queue<int> pq;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        pq.push(a[i]);
        if (vis[i]) {
            ans += pq.top();
            // cout << i << " " << pq.top() << '\n';
            pq.pop();
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}