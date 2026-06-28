#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1550;
int n,m,k,match[N],cnt,ans;
bool vis[N];
vector<int> G[N];

bool dfs(int u){
    for(auto &v : G[u]){
        if(vis[v])continue;
        vis[v] = 1;
        if(!match[v] || dfs(match[v])){
            match[v] = u;
            return true;
        }
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin >> m >> n >> k;
    for(int i=1;i<=k;i++){
        int u,v;cin >> u >> v;
        G[u].push_back(v);
    }
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i))cnt++;
    }
    ans = cnt;
    for(int i=1;i<=m;i++){
        int backup[N];
        memcpy(backup, match, sizeof(match));
        int sum = cnt;
        memset(vis,0,sizeof(vis));
        auto f = [&](auto self,int v) -> bool {
            for(auto &j : G[v]){
                if(vis[j])continue;
                vis[j] = 1;
                if(!backup[j] || self(self,backup[j])){
                    backup[j] = v;
                    return true;
                }
            }
            return false;
        };
        if(G[i].size() <= 1)continue;
        G[m + 1] = G[i];
        G[m + 2] = G[i];
        if(f(f,m + 1))sum++;
        memset(vis,0,sizeof(vis));
        if(f(f,m + 2))sum++;
        G[m + 1].clear();
        G[m + 2].clear();
        ans = max(ans,sum);
    }
    cout << ans << '\n';
    return 0;
}