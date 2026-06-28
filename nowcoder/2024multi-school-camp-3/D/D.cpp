#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


int main() {
    freopen ("D.in", "r", stdin);
    freopen ("D.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pii> p(n + 1);
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        auto &[x, y] = p[i];
        cin >> x >> y;
        b.push_back(x); b.push_back(y);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (int i = 1; i <= n; i++) {
        p[i].first = lower_bound(b.begin(), b.end(), p[i].first) - b.begin() + 1;
        p[i].second = lower_bound(b.begin(), b.end(), p[i].second) - b.begin() + 1;
    }

    int m = b.size();
    vector<int> cnt(m + 1);
    for (int i = 1; i <= n; i++) {
        auto &[x, y] = p[i];
        cnt[x] += 1; cnt[y] += 1;
    }
    for (int i = 1; i <= m; i++)
        if (cnt[i] > n + 1) {
            cout << "No" << "\n";
            return 0;
        }
    vector<vector<int>> pos_same(m + 1);
    multiset<pii> st;
    for (int i = 1; i <= n; i++) {
        auto &[x, y] = p[i];
        if (x == y) pos_same[x].push_back(i);
        else st.insert({x, y});
    }
    priority_queue<pii> pq;
    for (int i = 1; i <= m; i++) {
        int num = pos_same[i].size(), v = i;
        if (num == 0) continue;
        pq.push({num, v});
    }
    int lst = -1;
    vector<pii> ans;
    set<pii>::iterator lst_it = st.begin();
    while (!pq.empty()) {
        stack<pii> stk;
        while (!pq.empty() && (stk.empty() || stk.top().second == lst)) {
            stk.push(pq.top()); pq.pop();
        }
        if (stk.top().second == lst) {  // 取空了，需要找一个不是 x=y 的
            for (auto it = lst_it; it != st.end(); ++it) {
                auto [x, y] = *it;
                if (x != lst && y != lst) {
                    lst_it = next(it);
                    ans.push_back({x, y});
                    st.erase(it);
                    lst = y;
                    while (!stk.empty()) {
                        auto [num, v] = stk.top(); stk.pop();
                        pq.push({num, v});
                    }
                    break;
                }
            }
        }
        else {
            auto [num, v] = stk.top(); stk.pop();
            ans.push_back({v, v}); num -= 1; lst = v;
            if (num > 0) stk.push({num, v});
            while (!stk.empty()) {
                auto [num, v] = stk.top(); stk.pop();
                pq.push({num, v});
            }
        }
    }
    while (!st.empty()) {
        auto [x, y] = *st.begin();
        if (lst == x) {
            ans.push_back({y, x});
            lst = x;
        }
        else {
            ans.push_back({x, y});
            lst = y;
        }
        st.erase(st.begin());
    }
    cout << "Yes" << "\n";
    for (auto [x, y] : ans) cout << b[x - 1] << " " << b[y - 1] << "\n";
    return 0;
}