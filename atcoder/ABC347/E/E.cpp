#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("E.in","r",stdin);
    int n, Q; cin >> n >> Q;
    vector<int> q(Q + 1, 0);
    for (int i = 1; i <= Q; i ++)
        cin >> q[i];
    set<int> st;
    vector<ll> cnt(Q + 1, 0);
    for (int i = 1; i <= Q; i++) {
        int x = q[i];
        if (st.count(x)) 
            st.erase(x);
        else
            st.insert(x);
        cnt[i] = st.size();
    }
    
    vector<vector<int> > pos(n + 1, vector<int>());
    for (int i = 1; i <= Q; i++)
        pos[q[i]].push_back(i);
    
    vector<ll> c(Q + 1, 0);
    auto add = [&](int x, int v) {
        for (; x <= Q; x += x & -x)
            c[x] += v;
    };
    auto query = [&](int x) {
        ll res = 0;
        for (; x; x -= x & -x)
            res += c[x];
        return res;
    };

    for (int i = 1; i <= Q; i++) 
        add(i, cnt[i]);
    
    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        if (pos[i].size() & 1)
            pos[i].push_back(Q + 1);
        
        for (int j = 0; j < pos[i].size(); j += 2) {
            ans += query(pos[i][j + 1] - 1) - query(pos[i][j] - 1);
        }
        cout << ans << ' ';
    }
    return 0;
}