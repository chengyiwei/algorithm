#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef tuple<int, int, int> t3;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<t3> a(k + 1);
    for (int i = 1; i <= k; i++) {
        auto &[x, y, id] = a[i];
        cin >> x >> y; id = i;
    }
    stack<int> stk;
    vector<int> in_st(k + 1, 0);
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= k; i++) {
        auto [x, y, id] = a[i];
        if (i > 1) {
            auto [x_pre, y_pre, id_pre] = a[i - 1];
            if (x == x_pre)
                continue;
        }
        while (!stk.empty()) {
            auto [x1, y1, id1] = a[stk.top()];
            auto [x2, y2, id2] = a[i];
            if (y1 < y2) break;
            in_st[stk.top()] = 0;
            stk.pop();
        }
        stk.push(i); in_st[i] = 1;
    }
    ll ans = 0;
    vector<t3> p;
    p.push_back({0, 0, 0});
    for (int i = 1; i <= k; i ++) {
        if (in_st[i]) 
            p.push_back(a[i]);
    }
    p.push_back({n, m + 1, k + 1});
    for (int i = 0; i + 1 < p.size(); i++) {
        auto [x1, y1, id1] = p[i];
        auto [x2, y2, id2] = p[i + 1];
        ans += 1ll * (x2 - x1) * (y2 - 1);
    }
    cout << ans << endl;
    vector<int> ans_id(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        auto [x, y, id] = a[i];
        if (in_st[i]) 
            ans_id[id] = 1;
    }
    for (int i = 1; i <= k; i++) 
        cout << ans_id[i] << " ";
    cout << endl;
}

int main() {
    freopen ("F1.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}