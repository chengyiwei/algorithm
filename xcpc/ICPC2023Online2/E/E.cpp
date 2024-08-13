#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

vector<vector<int> > G;

int main(){
    freopen("E.in","r",stdin);
    int n=read(),m=read();
    G.assign(n+1,vector<int>());
    vector<int> fa(n+1,0);
    for(int i=2;i<=n;i++){
        int x=read();
        fa[i]=x;
    }
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    queue<int> q;q.push(1);
    vector<int> dis(n+1,0); dis[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:G[u]){
            while(dis[v]==0){
                dis[v]=dis[u]+1;
                q.push(v);
                v=fa[v];
            }
        }
    }
    for(int i=2;i<=n;i++){
        printf("%d ",dis[i]-1);
    }
    return 0;
}