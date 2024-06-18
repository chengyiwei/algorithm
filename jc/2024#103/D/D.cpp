#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n; ll m; cin >> n >> m;
    vector<ll> a(n + 1);
    set<ll> st;
    for (int i = 1; i <= n; i++) cin >> a[i], st.insert(a[i]);
    if (st.size() == 1) {printf ("0\n"); return 0;}
    
    ll L = 0, R = a[n];

    auto check = [&] (ll L) {
        ll res = 0;
        for (int i = 1; i + 1 <= n; i++) {
            ll now = (a[i + 1] - a[i] + L - 1) / L;
            res += max(now - 1, 0ll);
        }
        return max(res - 1, 0ll);
    };

    while (L + 1 < R) {
        ll mid = (L + R) / 2;
        if (check (mid) <= m) R = mid;
        else L = mid;
    }
    cout << R << endl;
    return 0;
}