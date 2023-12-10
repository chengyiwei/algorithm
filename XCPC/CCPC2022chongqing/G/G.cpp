#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
int n;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
struct Edge{
    int from,to;
    LL w;
    Edge(int x,int y,int z){from=x;to=y;w=z;}
};
vector<Edge> E;
vector<int> G[maxn];
LL c[maxn];
double ans;
void DFS(int u,int fa,LL sum_c,LL sum_m){
    ans=max(ans,(double)sum_c/(2*sum_m));
    for(int i=0;i<G[u].size();i++){
        auto& e=E[G[u][i]];
        if(e.to==fa) continue;
        DFS(e.to,u,sum_c+c[e.to],sum_m+e.w);
    }
}
void add_e(int x,int y,int w){
    E.push_back((Edge){x,y,w});
    G[x].push_back(E.size()-1);
}
int main(){
    freopen("G.in","r",stdin);
    n=read();
    for(int i=1;i<=n;i++) c[i]=read();
    for(int i=1;i<=n;i++){
        int x=read(),y=read(),w=read();
        add_e(x,y,w);add_e(y,x,w);
    }
    DFS(0,-1,0,0);
    printf("%.15lf",ans);
    return 0;
}