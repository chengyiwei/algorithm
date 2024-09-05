#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    int ans = 0;
    stack<pii> stk;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        int mx = 0;
        while (!stk.empty()) {
            if (stk.top().second == b) {
                a += stk.top().first - mx;
                stk.pop();
            }
            else if (stk.top().first <= a) {
                mx = max(mx, stk.top().first);
                stk.pop();
            }
            else break;
        }

        stk.push({a, b});
        ans = max(ans, stk.top().first);
        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}