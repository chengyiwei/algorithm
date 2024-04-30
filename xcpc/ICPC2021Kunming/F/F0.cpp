#include<bits/stdc++.h>
using namespace std;
const double INF=1e6;
int n;
double ans;
vector<int> a;
vector<vector<int> > G;
vector<int> fa,dep;

void dfs(int u,int f,int dp){
    fa[u]=f;dep[u]=dp;
    for(int& v:G[u]){
        if(v==f) continue;
        dfs(v,u,dp+1);
    }
}

double Get(int x,int y){
    double sum=0;
    int cnt=0;
    while(x!=y){
        if(dep[x]>dep[y]) swap(x,y);
        sum+=a[y];cnt++;
        y=fa[y];
    }
    cnt++;sum+=a[x];
    return (sum)/cnt;
}

int main(){
    freopen("F.in","r",stdin);
    freopen("F0.out","w",stdout);
    scanf("%d",&n);
    
    a.assign(n+1,0);G.assign(n+1,vector<int>());
    fa.assign(n+1,0);dep.assign(n+1,0);

    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1,-1,1);

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            double now=Get(i,j);
            ans=max(ans,now*now/4);
        }
    }
    printf("%.4lf\n",ans);
    return 0;
}