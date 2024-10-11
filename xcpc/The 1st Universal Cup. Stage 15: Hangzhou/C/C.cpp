#include <bits/stdc++.h>
using namespace std;

void NO() {
    cout << "NO" << endl;
    exit(0);
}

int main() {
    freopen ("C.in", "r", stdin);
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<char> op(n + 1);
    vector<int> dep(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int x, fa; cin >> x >> fa;
        g[fa].push_back(x); dep[x] = dep[fa] + 1;
        string s; cin >> s;
        op[x] = s[0];
    }

    vector<pair<int,int>> ans;

    function<bool(int, int)> cmp = [&] (int x, int y) {
        return dep[x] < dep[y];
    };

    function<int(int)> dfs = [&] (int u) {
        vector<int> T, D, C;
        for (int v : g[u]) {
            int t = dfs(v);
            if (t == 0) continue;
            if (op[t] == 'T') T.push_back(t);
            if (op[t] == 'D') D.push_back(t);
            if (op[t] == 'C') C.push_back(t);
        }
        if (op[u] == 'T') T.push_back(u);
        if (op[u] == 'D') D.push_back(u);
        if (op[u] == 'C') C.push_back(u);

        int ret = 0;
        sort(T.begin(), T.end(), cmp);
        int i, j;
        for (i = 0; i + 1 < T.size();) {
            if (dep[i] == dep[i + 1]) {
                ans.push_back({T[i], T[i + 1]});
                i += 2;
            }
            else {
                if (ret == 0) {ret = T[i]; i += 1;}
                else NO();
            }
        }
        if (i < T.size()) {
            if (ret == 0) {ret = T[i]; i += 1;}
            else NO();
        }
        sort(D.begin(), D.end(), cmp);
        sort(C.begin(), C.end(), cmp);
        if (D.size() == C.size()) {
            for (i = 0; i < D.size(); i++) {
                if (dep[D[i]] < dep[C[i]])
                    ans.push_back({D[i], C[i]});
                else NO();
            }
        }
        else if (D.size() == C.size() + 1) {
            for (i = 0, j = 0; i < C.size(); i++) {
                if (dep[D[j]] < dep[C[i]]) {
                    ans.push_back({D[j], C[i]});
                    j += 1; 
                }
                else if (ret == 0) {ret = D[j]; j += 1;}
                else NO();
            }
            if (j < D.size()) {
                if (ret == 0) {ret = D[j];}
                else NO();
            }
        }
        else if (D.size() + 1 == C.size()) {
            for (i = 0, j = 0; i < D.size(); i++) {
                if (dep[D[i]] < dep[C[j]]) {
                    ans.push_back({D[i], C[j]});
                    j += 1;
                }
                else if (ret == 0) {ret = C[j]; j += 1;}
                else NO();
            }
            if (j < C.size()) {
                if (ret == 0) {ret = C[j]; }
                else NO();
            }
        }
        else NO();

        return ret;
    };

    int root = dfs(1);
    if (root != 0) NO();
    cout << "YES" << '\n';
    for (auto p : ans) cout << p.first << " " << p.second << '\n';
    return 0;
}