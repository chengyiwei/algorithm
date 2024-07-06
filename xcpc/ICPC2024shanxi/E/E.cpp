#include <bits/stdc++.h>
using namespace std;
int K, n; 
int dis (int x, int y) {
    if (x > y) swap(x, y);
    return min(y - x, K - y + x);
}
int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin >> K >> n;
    vector<int> a(n);
    vector<vector<int> > To(n, vector<int>()), In(n, vector<int>());

    auto add_e = [&] (int x, int y) {
        To[x].push_back(y);
        In[y].push_back(x);
    };

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int j = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        do {
            int pre = (j - 1 + n) % n, nxt = (j + 1) % n;
            if (dis(a[pre], a[i]) <= dis(a[j], a[i]) && dis(a[nxt], a[i]) <= dis(a[j], a[i]))
                add_e(i, j);
            if (dis(a[nxt], a[i]) < dis(a[j], a[i]))
                break;
            j = nxt;
        } while (1);
    }
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.clear();
        for (auto x : To[i])
            st.insert(x);
        for (auto x : In[i])
            st.insert(x);
        ans = max(ans, int(st.size()));
    }
    for (int i = 0; i < n; i++) {
        if (To[i].size() == 2) {
            st.clear();
            for (auto x : To[To[i][0]])
                st.insert(x);
            if (st.count(To[i][1])) 
                ans = max(ans, 3);
            st.clear();
            for (auto x : To[To[i][1]])
                st.insert(x);
            if (st.count(To[i][0])) 
                ans = max(ans, 3);
        }
    }
    cout << ans << endl;
    return 0;
}