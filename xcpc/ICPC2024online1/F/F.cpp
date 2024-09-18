#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 2); a[0] = a[n + 1] = INF;
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<int> stk; stk.push(0);
    vector<ll> cnt(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && a[stk.top()] < a[i]) stk.pop();
        ll now = 0;
        if (!stk.empty()) now = i - stk.top() - 1;
        stk.push(i);
        cnt[i] += now;
    }
    while (!stk.empty()) stk.pop(); stk.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && a[stk.top()] < a[i]) stk.pop();
        ll now = 0;
        if (!stk.empty()) now = stk.top() - i - 1;
        stk.push(i);
        cnt[i] += now;
    }
    ll ans  = 0;
    for (int i = 1; i <= n; i++) ans += cnt[i];
    cout << ans << '\n';
}

int main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}