#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > G;
string s;
vector<int> ans;
vector<vector<int> > now;
bool dfs(int u, int ffa) {
    if (s[u] == 'R')
        ffa = u;
    now[ffa].push_back(u);
    for (auto &v : G[u])
        if(!dfs(v, ffa))
            return 0;
    
    if (s[u] == 'R') {
        int siz = now[u].size();
        if (siz % 3 == 0) {
            if (siz == 0) { printf("-1\n"); return 0; }
            for (int i = 0; i < siz; i ++)
                ans[now[u][i]] = 1;
        }
        if (siz % 3 == 1) {
            if (siz == 1) { printf("-1\n"); return 0; }
            ans[now[u][0]] = 2; ans[now[u][1]] = 2;
            for (int i = 2; i < siz; i ++)
                ans[now[u][i]] = 1;
        }
        if (siz % 3 == 2) {
            ans[now[u][0]] = 2;
            for (int i = 1; i < siz; i ++)
                ans[now[u][i]] = 1;
        }
    }
    return 1;
}

int main() {
    freopen("J.in", "r", stdin);
    int n; scanf("%d", &n);
    G.assign(n + 1, vector<int>()); now.assign(n + 1, vector<int>()); ans.assign(n + 1, 0);
    cin >> s; s = " " + s;
    for (int i = 2; i <= n; i++) {
        int fa; scanf("%d", &fa);
        G[fa].push_back(i);
    }
    if(!dfs(1, 0))
        return 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0) ans[i] = 1;
        printf("%d", ans[i]);
    }
    return 0;
}