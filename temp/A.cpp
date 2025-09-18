#include <bits/stdc++.h>
using namespace std;
/*
6 5
1 3
3 2
3 5
3 6
1 4
1 2 3 4 5 6
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<map<int, int>> mp(n + 1);
    vector<pair<int, int>> new_edges;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        mp[u][v] = 1; mp[v][u] = 1;
    }

    vector<int> p(n + 1);
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> p[i];
    int now = 1;
    int root = p[1];
    stack<int> stk;

    function<void(int)> dfs = [&] (int u) -> void {
        if (now > n) return ;
        visited[u] = 1;
        vector<int> er;
        for (auto _ : mp[u]) {
            int v = _.first;
            if (visited[v] == 1) er.push_back(v);
        }
        for (auto &x : er) {
            mp[u].erase(x);
        }
        int v = p[now];
        if (mp[u].find(v) != mp[u].end()) {
            now += 1;
            stk.push(u);
            dfs(v);
        }
        else if (mp[u].size() == 0) {
            if (u != root) {
                int tp = stk.top(); stk.pop();
                dfs(tp);
            }
            else {
                new_edges.push_back({u, v});
                now += 1;
                stk.push(u);
                dfs(v);
            }
        }
        else {
            new_edges.push_back({u, v});
            now += 1;
            stk.push(u);
            dfs(v);
        }
    };

    now = 2; 
    dfs(root);

    cout << new_edges.size() << '\n';
    for (auto &e : new_edges) {
        cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}

/*

3 2
1 2
2 3
1 2 3

6 6
1 3
1 4
2 3
3 4
3 6
5 6
1 2 3 4 5 6


8 8
2 8
3 8
5 6
1 6
6 3
8 7
2 3
4 3
1 8 7 5 4 2 3 6


*/