#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> s(n + 1,0);
    int m = -1;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; m = max(m, x);
        s[x] += 1;
    }
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];

    auto check = [&] (int x, int mid) -> bool {
        int ret = 0;
        for (int l = 0; l <= m; l += x) {
            int r = min(m, l + mid);
            ret += s[r] - (l == 0 ? 0 : s[l - 1]);
        }
        return ret >= n / 2 + 1;
    };

    vector<int> ans(n + 1);
    for (int x = 1; x <= n; x++) {
        int l = -1, r = x;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (check(x, mid)) r = mid;
            else l = mid;
        }
        ans[x] = r;
    }

    while (q--) {
        int x; cin >> x;
        cout << ans[x] << ' ';
    }
    cout << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}