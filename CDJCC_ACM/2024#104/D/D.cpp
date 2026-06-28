#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n; ll h; cin >> h;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    auto calc = [&] (vector<ll> q) {
        int cnt = 0;
        ll now_h = h; int j = 1;
        while (j <= n) {
            if (now_h > a[j]) {
                now_h += a[j] / 2;
                j += 1;
            }
            else if (cnt < 3) {
                now_h *= q[cnt];
                cnt += 1;
            }
            else break;
        }
        return j - 1;
    };

    int ans = 0;
    for (int i = 0; i < 3; i++) {
        vector<ll> q(3);
        for (int j = 0; j < 3; j++) q[j] = (i == j ? 3 : 2);
        ans = max(ans, calc(q));
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}