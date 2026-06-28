#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int top, cz;
    bool operator < (const Node &rhs) const {
        return cz < rhs.cz || (cz == rhs.cz && top < rhs.top);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> c(m + 1);
    vector<Node> p(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= m; i++) { 
        cin >> c[i];
        if (mp.find(c[i]) == mp.end()) mp[c[i]] = 1;
        else mp[c[i]] += 1;
    }
    for (int i = 1; i <= n; i++) p[i] = {a[i], a[i] - b[i]};
    sort(p.begin() + 1, p.end());
    int pos = 1; ll ans = 0;
    while (pos <= n) {
        if (mp.empty()) break;
        auto it = mp.end(); --it;
        int t = it->first, cnt = it->second;
        if (t >= p[pos].top) {
            mp.erase(it);
            int len = t - p[pos].top + 1;
            int now = (len + p[pos].cz - 1) / p[pos].cz;
            ans += 1ll * now * cnt;
            t -= now * p[pos].cz;
            if (t > 0) {
                if (mp.find(t) == mp.end()) mp[t] = cnt;
                else mp[t] += cnt;
            } 
        }
        else {
            pos += 1;
        }
    }
    cout << ans * 2 << endl;
}

int main() {
    freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T = 1;
    while (T--) solve();
    return 0;
}