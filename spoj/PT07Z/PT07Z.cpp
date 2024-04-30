#include<bits/stdc++.h>
using namespace std;

int n,d;
vector<int> d1,d2;
vector<vector<int> > E;

void dfs(int u,int fa){
    d1[u]=d2[u]=0;
    for(auto v:E[u]){
        if(v==fa) continue;
        dfs(v,u);
        int t=d1[v]+1; //走 v 这条路的最长路径
        if(t>d1[u]) 
            d2[u]=d1[u],d1[u]=t;
        else if(t>d2[u])
            d2[u]=t;
    }
    d=max(d,d1[u]+d2[u]);
}

int main(){
    freopen("PT07Z.in","r",stdin);
    scanf("%d",&n);
    d1.resize(n+1,0),d2.resize(n+1,0);
    E.resize(n+1,vector<int>());
    for(int i=1;i<n;i++){
        int x,y;scanf("%d%d",&x,&y);
        E[x].push_back(y);E[y].push_back(x);
    }
    dfs(1,0);
    printf("%d\n",d);
    return 0;
}