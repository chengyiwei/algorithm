#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef tuple<int, int, int> t3;
bool cmp (t3 a, t3 b) {
    auto [x1, y1, id1] = a;
    auto [x2, y2, id2] = b;
    return x1 < x2 || (x1 == x2 && y1 > y2);
}
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<t3> a(k + 1);
    for (int i = 1; i <= k; i++) {
        auto &[x, y, id] = a[i];
        cin >> x >> y; id = i;
    }
    stack<int> stk;
    vector<int> in_st(k + 1, 0), pre(k + 1, -1);
    sort(a.begin() + 1, a.end(), cmp);
    for (int i = 1; i <= k; i++) {
        auto [x, y, id] = a[i];
        int p_ = -1;
        while (!stk.empty()) {
            int tp = stk.top();
            auto [x1, y1, id1] = a[tp];
            auto [x2, y2, id2] = a[i];
            if (y1 < y2) break;
            p_ = tp;
            in_st[tp] = 0;
            stk.pop();
        }
        stk.push(i); in_st[i] = 1;
        pre[stk.size()] = p_;
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
    for (int i = 1; i < p.size() - 1; i++) {
        ll add = 0;
        auto [x0, y0, id0] = p[i - 1];
        auto [x1, y1, id1] = p[i];
        auto [x2, y2, id2] = p[i + 1];
        if (pre[i] == -1) {
            add = 1ll * (x1 - x0) * (y2 - y1);
        }
        else {
            auto [x_pre, y_pre, id_pre] = a[pre[i]];
            add = 1ll * (x1 - x_pre) * (y2 - y1) + 1ll * (x_pre - x0) * (min(y_pre, y2) - y1);
        }
        ans_id[id1] = add;
    }
    for (int i = 1; i <= k; i++) 
        cout << ans_id[i] << " ";
    cout << endl;
}

int main() {
    freopen ("F2.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}