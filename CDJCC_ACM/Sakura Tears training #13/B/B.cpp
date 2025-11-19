#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end(), [](auto &a, auto &b) {
        return a.first + a.second < b.first + b.second;
    });
    if (n % 2 == 0) {
        long long sum_r = 0, sum_lr = 0;
        for (int i = 0; i < n; i++) {
            sum_r += p[i].second;
            if (i < n / 2) sum_lr += p[i].first + p[i].second;
        }
        long long ans = sum_r - sum_lr;
        for (auto [l, r] : p) ans += r - l;
        cout << ans << '\n';
    }
    else {
        long long sum_r = 0, sum_lr = 0;
        for (int i = 0; i < n; i++) {
            sum_r += p[i].second;
            if (i < n / 2) sum_lr += p[i].first + p[i].second;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                ans = max(ans, (sum_r - p[i].second) - (sum_lr - (p[i].first + p[i].second) + p[n / 2].first + p[n / 2].second));
            }
            else {
                ans = max(ans, (sum_r - p[i].second) - sum_lr);
            }
        }
        for (auto [l, r] : p)
            ans += r - l;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}