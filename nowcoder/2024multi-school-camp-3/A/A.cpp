#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n, L, R; cin >> n >> L >> R;
    if (R >= n && L <= n) return cout << "Yes" << endl, 0;
    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x & 1) p[i] = x - 1 >> 1;
        else p[i] = x - 2 >> 1;
    }
    sort(p.begin() + 1, p.end());
    int cnt = (n - R + (R - L) - 1) / (R - L);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += min(p[i], (ll)cnt);
    if (sum >= 1ll * cnt * L) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}