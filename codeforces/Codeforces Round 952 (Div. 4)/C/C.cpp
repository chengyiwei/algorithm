#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll sum = 0, pre_max = 0;
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i], pre_max = max(pre_max, a[i]);
        if (sum - pre_max == pre_max)
            ret += 1;
    }
    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    freopen ("C.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}