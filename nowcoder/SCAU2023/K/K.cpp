#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge{
    int from,to,v,c;
    
    Edge(int from,int to,int v,int c):from(from),to(to),v(v),c(c){}
};
vector<Edge> edges;
vector<vector<int>> G;
void add_e(int u,int v,int w,int c){
    edges.push_back(Edge(u,v,w,c));
    G[u].push_back(edges.size()-1);
}

vector<int> fa;
int get_fa(int x){
    return fa[x]==x?x:fa[x]=get_fa(fa[x]);
}

int check(double mid){
    double sum=0;
    int now_cnt=n;
    fa.resize(n+1);
    iota(fa.begin(),fa.end(),0);
    sort(edges.begin(),edges.end(),[mid](const Edge &a,const Edge &b){
        return a.v-mid*a.c>b.v-mid*b.c;
    });
    for(auto& e:edges){
        int u=get_fa(e.from),v=get_fa(e.to);
        if(u==v) continue;
        fa[u]=v;sum+=e.v-mid*e.c;
        now_cnt--; if(now_cnt<=k) break;
    }
    return sum>=0;
}

int main(){
    freopen("K.in","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    if(k==n){printf("%.6lf",0);return 0;}
    G.assign(n+1,vector<int>());
    for(int i=1;i<=m;i++){
        int u,v,w,c;
        scanf("%d%d%d%d",&u,&v,&w,&c);
        add_e(u,v,w,c);
        add_e(v,u,w,c);
    }
    double L=0,R=1e9;
    while(abs(R-L)>=1e-8){
        double mid=(L+R)/2;
        if(check(mid)) L=mid;
        else R=mid;
    }
    printf("%.6lf\n",L);
    return 0;
}