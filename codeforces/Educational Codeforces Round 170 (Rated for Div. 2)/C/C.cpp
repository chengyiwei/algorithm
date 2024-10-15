#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x] += 1;
    }
    vector<pair<int, int>> v;
    for (auto [x, y] : mp) {
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    int ans = 0, now_cnt = 0;
    for (int i = 0, j = 0; i < v.size(); i++) {
        while (j < v.size() && (j == i || (v[j].first - v[j - 1].first == 1 && v[j].first - v[i].first < k)) ) {
            now_cnt += v[j].second;
            j += 1;
        }
        ans = max(ans, now_cnt);
        now_cnt -= v[i].second;
    }
    
    cout << ans << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}