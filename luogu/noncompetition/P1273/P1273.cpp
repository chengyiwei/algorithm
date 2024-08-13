#include<bits/stdc++.h>
using namespace std;
const int maxn = 3005;
const int INF = 0x3f3f3f3f;

int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n,m;
int dp[maxn][maxn],val[maxn],siz[maxn];

struct Edge{
    int from,to,w;
    Edge(int u,int v,int w):from(u),to(v),w(w){}
};

vector<Edge> edges;
vector<int> G[maxn];

void add_edge(int u,int v,int w){
    edges.push_back(Edge(u,v,w));
    G[u].push_back(edges.size()-1);
}

void dfs(int u){
    if(u > n-m){
        dp[u][1] = val[u];
        siz[u] = 1;
        return ;
    }
    int sum = 0;
    for(int i=0;i<G[u].size();i++){
        Edge& e = edges[G[u][i]];
        int v = e.to, w = e.w;
        dfs(v); siz[u] += siz[v];
        sum += siz[v];
        for(int j=sum;j>0;j--)
            for(int k=1;k<=min(j,siz[v]);k++)
                dp[u][j] = max(dp[u][j],dp[u][j-k]+dp[v][k]-w);
    }
}

int main(){
    freopen("P1273.in","r",stdin);
    memset(dp,~INF,sizeof dp);
    n=read(); m=read();
    for(int u=1;u<=n-m;u++){
        int k=read();
        for(int j=1;j<=k;j++){
            int v = read(), w = read();
            add_edge(u,v,w);
        }
    }
    for(int i=n-m+1;i<=n;i++)
        val[i] = read();
    for(int i=1;i<=n;i++)
        dp[i][0] = 0;
    dfs(1);
    for(int i=m;i>=0;i--){
        if(dp[1][i] >= 0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}