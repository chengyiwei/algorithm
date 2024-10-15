#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<pair<ll, int>> s;
    for (int i = 1; i <= n; i++) {
        ll sum = a[i], cnt = 1;
        while (!s.empty() && s.top().first * cnt >= sum) {
            sum += s.top().first * s.top().second;
            cnt += s.top().second;
            s.pop();
        }
        s.push({sum / cnt, cnt - sum % cnt});
        if (sum % cnt != 0)
            s.push({sum / cnt + 1, sum % cnt});
    }
    ll mx = s.top().first, mi = 0;
    while (!s.empty()) {
        if (s.size() == 1) mi = s.top().first;
        s.pop();
    }
    cout << mx - mi << '\n';
}

int main() {
    freopen ("A.in" ,"r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int _; cin >> _;
    while (_ --) solve();
    return 0;
}