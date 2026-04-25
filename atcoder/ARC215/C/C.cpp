#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    int x, y, z;
};

void solve() {
    int n; cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        a[i].id = i + 1;
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    
    vector<vector<int>> g(n + 1);
    sort(a.begin(), a.end(), [](const Node &a, const Node &b) { return a.x > b.x; });

    for (int i = 0; i < n - 1; i++) {
        if (a[i].x == a[i + 1].x) {
            // cout << "add edge " << a[i + 1].id << " -> " << a[i].id << "\n";
            g[a[i + 1].id].push_back(a[i].id);
        }
        // cout << "add edge " << a[i].id << " -> " << a[i + 1].id << "\n";
        g[a[i].id].push_back(a[i + 1].id); 
    }

    sort(a.begin(), a.end(), [](const Node &a, const Node &b) { return a.y > b.y;});
    for (int i = 0; i < n - 1; i++) {
        if (a[i].y == a[i + 1].y) {
            // cout << "add edge " << a[i + 1].id << " -> " << a[i].id << "\n";
            g[a[i + 1].id].push_back(a[i].id);
        }
        // cout << "add edge " << a[i].id << " -> " << a[i + 1].id << "\n";
        g[a[i].id].push_back(a[i + 1].id);
    }

    sort(a.begin(), a.end(), [](const Node &a, const Node &b) { return a.z > b.z;});
    for (int i = 0; i < n - 1; i++) {
        if (a[i].z == a[i + 1].z) {
            // cout << "add edge " << a[i + 1].id << " -> " << a[i].id << "\n";
            g[a[i + 1].id].push_back(a[i].id);
        }
        // cout << "add edge " << a[i].id << " -> " << a[i + 1].id << "\n";
        g[a[i].id].push_back(a[i + 1].id); 
    }

    vector<int> dfn(n + 1, 0), low(n + 1, 0), scc(n + 1, 0);
    vector<bool> in_stack(n + 1, false);
    stack<int> stk;
    int cnt, scc_cnt;

    function<void(int)> tarjan = [&] (int u) {
        dfn[u] = low[u] = ++cnt;
        stk.push(u); in_stack[u] = true;
        for (int v : g[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
            else if (in_stack[v]) low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            scc_cnt++;
            while (true) {
                int x = stk.top(); stk.pop();
                in_stack[x] = false;
                scc[x] = scc_cnt;
                if (x == u) break;
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    vector<int> du(scc_cnt + 1, 0), cnt_scc(scc_cnt + 1, 0);
    for (int i = 1; i <= n; i++) {
        cnt_scc[scc[i]]++;
        for (int v : g[i]) {
            if (scc[i] != scc[v]) du[scc[v]]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        if (du[i] == 0) ans += cnt_scc[i];
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}