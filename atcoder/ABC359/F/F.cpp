#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
ll calc(ll x) {
    return (x + 1) * (x + 1) - x * x;
}
int main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n + 1), d(n + 1, 0);
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    for (int i = 1; i <= n; i++) {
        d[i] = 1;
        cin >> a[i];
        pq.push({calc(d[i]) * a[i] , i});
    }
    int cnt = n - 2;
    while (cnt--) {
        auto [val, idx] = pq.top(); pq.pop();
        d[idx]++;
        pq.push({calc(d[idx]) * a[idx], idx});
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += d[i] * d[i] * a[i];
    cout << ans << endl;
    return 0;
}