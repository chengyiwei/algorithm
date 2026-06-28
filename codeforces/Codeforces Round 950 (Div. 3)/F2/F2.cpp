#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    int x, y, id;
    Node() {};
    Node(int x, int y, int id) : x(x), y(y), id(id) {};
    bool operator < (const Node &a) const {
        return x < a.x || (x == a.x && y > a.y);
    }
};


void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<Node> a(k + 2);
    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        a[i] = Node(x, y, i);
    }
    a[0] = Node(0, 0, 0); a[k + 1] = Node(n + 1, m + 1, k + 1);
    sort(a.begin() , a.end());
    vector<int> pre(k + 2, -1), in_stk(k + 2, 0), nxt(k + 2, -1);
    stack<int> stk;
    for (int i = 0; i <= k + 1; i++) {
        while (stk.size() && a[stk.top()].y >= a[i].y)
            stk.pop();
        if (stk.size())
            pre[i] = stk.top();
        else 
            pre[i] = -1;
        stk.push(i);
    }
    ll ans = -m; int cur = k + 1;
    while (pre[cur] != -1) {
        int p = pre[cur];
        in_stk[cur] = 1; in_stk[p] = 1;
        nxt[p] = cur;
        ans += 1ll * (a[cur].x - a[p].x) * (a[cur].y - 1);
        cur = p;
    }
    cout << ans << endl;

    vector<ll> add(k + 2, 0); vector<int> new_pre(k + 2, -1);
    for (int i = 1; i <= k; i++) if (in_stk[i]) {
        int p_ = pre[i], n_ = nxt[i];
        add[i] -= 1ll * (a[i].x - a[p_].x) * (a[i].y - 1);
        add[i] -= 1ll * (a[n_].x - a[i].x) * (a[n_].y - 1);
        while (!stk.empty()) stk.pop();
        for (int j = p_; ; j++) {
            if (j == i) continue;
            while (stk.size() && a[stk.top()].y >= a[j].y)
                stk.pop();
            if (stk.size())
                new_pre[j] = stk.top();
            else 
                new_pre[j] = -1;
            stk.push(j);
            if (j == n_) break;
        }
        for (int j = n_; new_pre[j] != -1; j = new_pre[j]) {
            add[i] += 1ll * (a[j].x - a[new_pre[j]].x) * (a[j].y - 1);
        }
    }
    
    vector<ll> ret_add(k + 2, 0);
    for (int i = 1; i <= k; i++) {
        int id = a[i].id;
        ret_add[id] = add[i];
    }
    for (int i = 1; i <= k; i++) {
        cout << min(1ll, ret_add[i]) << " \n"[i == k];
    }
}

int main() {
    freopen ("F2.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}