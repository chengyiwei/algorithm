#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
struct Edge{
    int from,to,w;
    Edge(int u,int v,int w):from(u),to(v),w(w){}
};
vector<Edge> edges;
struct Bit{
    int c[32];
    Bit(){memset(c,0,sizeof(c));}
    Bit(int x){
        memset(c,0,sizeof(c));
        for(int i=0;i<=31;i++) c[i]=x>>i&1;
    }
    void Get(int x){
        for(int i=0;i<=31;i++){
            c[i]=x>>i&1;
        }
    }
};

int n,Q;
vector<int> F;
vector<vector<int> > G;
vector<Bit> s;

void dfs(int x,int fa=0){
    for(int i=0;i<G[x].size();i++){
        auto& e=edges[G[x][i]];
        if(e.to==fa) continue;
        F[e.to]=F[x]^e.w;
        dfs(e.to,x);
    }
}

void solve(){
    n=read();

    G.assign(n+1,vector<int>()); s.assign(n+1,Bit());F.assign(n+1,0); edges.clear();
    
    for(int i=1;i<n;i++){
        int u=read(),v=read(),w=read();
        edges.push_back(Edge(u,v,w));
        G[u].push_back(edges.size()-1);
        edges.push_back(Edge(v,u,w));
        G[v].push_back(edges.size()-1);
    }

    dfs(1);

    for(int i=1;i<=n;i++){
        Bit now(F[i]); 
        for(int j=0;j<=31;j++){
            s[i].c[j]=s[i-1].c[j]+now.c[j];
        }
    }

    Q=read();
    while(Q--){
        int l=read(),r=read(),x=read();
        Bit now(F[x]);
        LL ans=0;
        for(int i=0;i<=31;i++){
            if(now.c[i]==0)
                ans+=(LL)(s[r].c[i]-s[l-1].c[i])*(1<<i);
            else
                ans+=(LL)((r-l+1)-(s[r].c[i]-s[l-1].c[i]))*(1<<i);
        }
        printf("%lld\n",ans);
    }
}

int main(){
    freopen("E.in","r",stdin);
    freopen("E.out","w",stdout);
    int T=read();
    while(T--) solve();
}