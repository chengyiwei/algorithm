#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("D.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> du(n + 1, 0);
        vector<vector<int>> g(n + 1);
        int ans = 0;
        int cnt_leaf = 0, cnt_other = 0;
        int leaf_0 = 0, leaf_1 = 0;

        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            du[u] += 1, du[v] += 1;
            g[u].push_back(v); g[v].push_back(u);
        }
        string s; cin >> s; s = " " + s;
        
        for (int i = 1; i <= n; i++) {
            if (i == 1) continue;
            if (du[i] == 1) {
                if (s[i] == '?') cnt_leaf += 1;
                if (s[i] == '0') leaf_0 += 1;
                if (s[i] == '1') leaf_1 += 1;
            } 
            else {
                if (s[i] == '?') cnt_other += 1;
            }
        }

        int cnt = cnt_leaf + cnt_other + (s[1] == '?');

        if (s[1] == '?') {
            if (leaf_0 > leaf_1) {
                ans += leaf_0;
                ans += cnt_leaf / 2;
            }
            else if (leaf_0 < leaf_1) {
                ans += leaf_1;
                ans += cnt_leaf / 2;
            }
            else {
                if (cnt_other % 2 == 0) {
                    ans += cnt_leaf / 2;
                    ans += leaf_0;
                }
                else {
                    ans += (cnt_leaf + 1) / 2;
                    ans += leaf_0;
                }
            }
        }
        else {
            if (s[1] == '0') 
                ans += leaf_1;
            else 
                ans += leaf_0;
            ans += (cnt_leaf + 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}