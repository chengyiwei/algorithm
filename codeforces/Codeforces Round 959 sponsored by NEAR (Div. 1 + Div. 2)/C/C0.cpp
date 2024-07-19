#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve() {
    int n; cin >> n; ll X; cin >> X;
    vector<ll> a(n + 1, 0), sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; sum[i] = sum[i - 1] + a[i];
    }
 
    vector<ll> f(n + 1, 0); 
    auto check = [&] (int L, int R) {
        ll now = 0;
        for (int i = L; i <= R; i++) {
            now += a[i];
            if (now > X) now = 0;
        }
        return now != 0;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (check(i, j))
                ans += 1;
        }
    cout << ans << '\n';
}
 
int main() {
    freopen ("C.in", "r", stdin);
    freopen ("C0.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}