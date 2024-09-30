#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id, d, cnt;
    bool operator < (const Node B) const {
        return d < B.d;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<Node> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].d; a[i].id = i; a[i].cnt = 0;
    }
    sort(a.begin() + 1, a.end());
    if (a[1].d != 0) {cout << -1 << '\n'; return ;}
    int pos = 1;
    queue<Node> q; q.push(a[pos]); pos += 1;
    vector<pair<int, int>> ans;
    while (!q.empty()) {
        if (pos == n + 1) break;
        auto &[id, d, cnt] = q.front();
        if (d + 1 != a[pos].d || cnt == k) q.pop();
        else {
            ans.push_back({id, a[pos].id});
            a[pos].cnt += 1;
            q.push(a[pos++]);
            cnt += 1;
        }
    }
    
    if (pos != n + 1) cout << "-1" << '\n';
    else {
        cout << ans.size() << '\n';
        for (auto [u, v] : ans) {
            cout << u << " " << v << '\n';
        }
    }
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; T = 1;
    while (T--) solve();
    return 0;
}