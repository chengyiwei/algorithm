#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    
    vector<int> dfn(n + 1, 0), low(n + 1, 0), scc(n + 1, 0), in_stk(n + 1, 0);
    stack<int> stk;
    int cnt = 0, scc_cnt = 0;
    vector<vector<int>> g(n + 1, vector<int>());

    vector<vector<int>> p(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) cin >> p[i][j];
        for (int j = 1; j + 1 <= n; j++) {
            int u = p[i][j], v = p[i][j + 1];
            g[u].push_back(v);
        }
    }

    function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = ++cnt;
        stk.push(u); in_stk[u] = 1;
        for (int v : g[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (in_stk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            scc_cnt += 1;
            while (true) {
                int x = stk.top(); stk.pop();
                in_stk[x] = 0;
                scc[x] = scc_cnt;
                if (x == u) break;
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    vector<vector<int>> s_p(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= k; i++) {
        int tmp = 1;
        for (int j = 2; j <= n; j++) {
            if (scc[p[i][j]] == scc[p[i][j - 1]]) tmp += 1;
            else tmp = 1;
            s_p[i][j] = s_p[i][j - 1] + 2 * (tmp - 1);
        }
    }

    vector<vector<int>> nxt(k + 1, vector<int>(n + 1, n));
    for (int i = 1; i <= k; i++) {
        for (int j = n - 1; j >= 1; j--) {
            if (scc[p[i][j]] == scc[p[i][j + 1]]) nxt[i][j] = nxt[i][j + 1];
            else nxt[i][j] = j;
        }
    }

    int pre = 0;

    while (q--) {
        int id, l, r; cin >> id >> l >> r;
        id = (id + pre) % k + 1;
        l = (l + pre) % n + 1;
        r = (r + pre) % n + 1;
        if (l > r) {
            assert(false);
        }
        int nxt_pos = nxt[id][l], ans;
        if (nxt_pos >= r) {
            int len = r - l + 1;
            ans = (len * (len - 1)) / 2;
        }
        else {
            int ans1 = (s_p[id][r] - s_p[id][nxt_pos]) / 2;
            int len = nxt_pos - l + 1;
            int ans2 = (len * (len - 1)) / 2;
            ans = ans1 + ans2;
        }
        cout << ans << '\n';
        pre = ans;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}