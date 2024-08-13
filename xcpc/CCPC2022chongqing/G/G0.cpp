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

struct node{
    bool op;
    LL sum_m,sum_c;
}A[maxn];
void add_e(int x,int y,int w){
    E.push_back((Edge){x,y,w});
    G[x].push_back(E.size()-1);
}


void DFS(int u,int fa,double k){
    for(int i=0;i<G[u].size();i++){
        auto& e=E[G[u][i]];
        if(e.to==fa) continue;
        A[e.to].op=0;A[e.to].sum_c=c[e.to];A[e.to].sum_m=e.w;
        DFS(e.to,u,k);
        if((double)A[e.to].sum_c>k*A[e.to].sum_m){
            A[e.to].op=1;
            A[u].sum_c+=A[e.to].sum_c;A[u].sum_m+=A[e.to].sum_m;
        }
    }
}

bool check(double k){
    A[0].sum_c=0;A[0].sum_m=0;
    DFS(0,-1,k);
    return (double)A[0].sum_c>k*A[0].sum_m;
}

int main(){
    freopen("G.in","r",stdin);
    n=read();
    for(int i=1;i<=n;i++) c[i]=read();
    for(int i=1;i<=n;i++){
        int x=read(),y=read(),w=read();
        add_e(x,y,w);add_e(y,x,w);
    }
    double l=0,r=1e9;
    while(abs(r-l)>1e-8){
        double mid=(l+r)/2;
        // mid=0.4;
        if(check(mid)) ans=mid,l=mid;
        else r=mid;
    }
    printf("%.15lf",ans/2);
    return 0;
}