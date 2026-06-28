#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;

signed main() {
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);
    int k, n; cin >> k >> n;
    vector<int> a(n), b(n), cnt(k, 0);
    set<int> free;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    for (int i = 0; i < k; i++)
        free.insert(i);
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().first <= a[i]) {
            auto [tim, id] = pq.top(); pq.pop();
            cnt[id] += 1;
            free.insert(id);
        }
        if (!free.empty()) {
            auto it = free.lower_bound(i % k);
            if (it == free.end()) it = free.begin();
            int id = *it;
            free.erase(it);
            pq.push({a[i] + b[i], id});
        }
    }
    while (!pq.empty()) {
        auto [tim, id] = pq.top(); pq.pop();
        cnt[id] += 1;
        free.insert(id);
    }
    int mx_ = *max_element(cnt.begin(), cnt.end());
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        if (cnt[i] == mx_)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        cout << (i == ans.size() - 1 ? '\n' : ' '); 
    }
    return 0;
}