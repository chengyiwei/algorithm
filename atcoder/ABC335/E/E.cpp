#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,m;
typedef pair<int,int> pii;
vector<vector<int>> G;
vector<int> a;

int spfa(){
    vector<int> dis(n+1,INF);
    vector<int> vis(n+1,0);
    dis[1]=-1;
    queue<int> q;q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        vis[u]=0;
        for(auto v:G[u]){
            if(a[v]<=a[u])continue;
            if(dis[v]>dis[u]-1){
                dis[v]=dis[u]-1;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return dis[n];
}

int dij(){
    vector<int> dis(n+1,INF);
    vector<int> vis(n+1,0);
    priority_queue<pii,vector<pii>> pq;
    pq.push({0,1});dis[1]=-1;
    while(!pq.empty()){
        pii now=pq.top();pq.pop();
        int u=now.second,d=now.first;
        if(vis[u]) continue;
        vis[u]=1;
        for(int v:G[u]){
            if(a[v]<=a[u]) continue;
            if(dis[v]>dis[u]-1){
                dis[v]=dis[u]-1;
                pq.push({dis[v],v});
            }
        }
    }
    return dis[n];
}

int main(){
    freopen("E.in","r",stdin);
    scanf("%d%d",&n,&m);

    G.assign(n+1,vector<int>());a.assign(n+1,0);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    int ans1=spfa();
    int ans2=dij();
    int ans=max(ans1,ans2);
    printf("%d\n",ans==INF?0:-ans);

}