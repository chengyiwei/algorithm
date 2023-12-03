#include<bits/stdc++.h>
using namespace std;

int dis[maxn],vis[maxn];
bool bellman_ford(int s){
    queue<int> Q;
    for(int i=0;i<n;i++) d[i]=INF;
    d[s]=0;
    vis[s]=1;Q.push(s);
    while(!Q.empty()){
        int u=Q.front;Q.pop();
        vis[u]=false;
        for(int i=0;i<G[u].size();i++){
            edge& e=edge[G[u][i]];
            if(d[u]<INF&&d[e.to]>d[u]+e.dist)
            {
                d[e.to]=d[u]+e.dist;
                if(!vis[e.to]){
                    Q.push(e.to);
                    vis[e.to]=1;
                }
            }
        }
    }
}