#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x > y) swap(x, y);
    if (a > b) swap(a, b);
    if (a == b) {
        cout << x / a << '\n';
        return ;
    }

    auto check = [&] (int n) -> bool{
        int l = ceil(1.0 * (x - n * b) / (1.0 * a - b));
        int r = ceil(1.0 * (y - n * a) / (1.0 * b - a));
        return l <= r && r >= 0 && l <= n;
    };

    int l = 0, r = x + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
}

signed main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}