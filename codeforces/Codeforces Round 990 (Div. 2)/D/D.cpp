#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) pq.push({a[i], i});
    int pos = -1;
    vector<int> ans;
    while (1) {
        while (!pq.empty() && pq.top().second <= pos) pq.pop();
        if (pq.empty()) break;
        auto [val, idx] = pq.top(); pq.pop();
        ans.emplace_back(val);
        int len = idx - pos - 1;
        if (len == 0) {pos = idx; continue;}
        vector<int> id(len);
        for (int i = 0; i < len; i++) id[i] = pos + i + 1;
        sort(id.begin(), id.end(), [&](int x, int y) {
            return a[x] < a[y];
        });
        for (int i = 0; i < len; i++) {
            a.emplace_back(a[id[i]] + 1);
            pq.push({a.back(), a.size() - 1});
        }
        pos = idx;
    }
    assert((int)ans.size() == n);
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}