#include<bits/stdc++.h>
using namespace std;
const int maxn = 205;
struct Edge{
    int from,to,w;
    Edge(int u,int v,int w):from(u),to(v),w(w){}
};
vector<Edge> edges;
vector<int> G[maxn];

int dp[maxn][maxn],sum[maxn];
int n,q;

void dfs(int u,int fa){
    for(int i=0;i<G[u].size();i++){
        Edge& e = edges[G[u][i]];
        int v = e.to, w = e.w;
        if(v == fa) continue;
        dfs(v,u);
        sum[u] += sum[v] + 1;
        for(int j=min(q,sum[u]);j>=0;j--)
            for(int k=0;k<=min(j-1,sum[v]);k++)
                dp[u][j] = max(dp[u][j],dp[u][j-k-1]+dp[v][k]+w);
    }
}

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++){
        int u,v,w; scanf("%d%d%d",&u,&v,&w);
        edges.push_back(Edge(u,v,w));
        edges.push_back(Edge(v,u,w));
        G[u].push_back(edges.size()-2);
        G[v].push_back(edges.size()-1);
    }
    dfs(1,0);
    printf("%d\n",dp[1][q]);
    return 0;
}