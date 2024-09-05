#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    auto check = [&] (int x) -> bool {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= x)
                cnt += (a[i] - x + b[i] - 1) / b[i];
        }

        return cnt >= k;
    };

    int L = 0, R = 1e9 + 1;
    while (L + 1 < R) {
        int mid = (L + R) / 2;
        if (check(mid)) L = mid;
        else R = mid;
    }
    
    int cnt = 0, p = R;
    long long sum = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= L) {
            int t = (a[i] - p + b[i] - 1) / b[i];
            cnt += t;
            sum += 1ll * (a[i] + a[i] - (t - 1) * b[i]) * t / 2;
            a[i] -= t * b[i];
        }
        if (a[i] > 0) {
            pq.push({a[i], b[i]});
        }
    }
    int k_ = k - cnt;
    while (k_--) {
        if (pq.empty()) break;
        auto [ai, bi] = pq.top(); pq.pop();
        sum += ai;
        if (ai - bi > 0)
            pq.push({ai, ai - bi});
    }
    cout << sum << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}