#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5;
typedef pair<int,int> pii;
const int INF=2147483647;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

struct edge{
    int from,to,dist;
    edge(int u,int v,int d):from(u),to(v),dist(d){}
};

struct dij
{
    int n,m;
    vector<edge> E;
    vector<int> G[maxn];
    int dis[maxn];
    bool vis[maxn];
    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
        E.clear();
    }
    void add_e(int from,int to,int dist){
        E.push_back(edge(from,to,dist));
        m=E.size();
        G[from].push_back(m-1);
    }
    void do_dij(int st){
        priority_queue<pii,vector<pii>,greater<pii> > Q;
        for(int i=0;i<n;i++) dis[i]=INF;dis[st]=0;
        memset(vis,0,sizeof vis);
        Q.push(make_pair(0,st));
        while(!Q.empty()){
            pii now=Q.top();Q.pop();
            int y=now.second;
            if(vis[y]) continue;
            vis[y]=1;
            for(int i=0;i<G[y].size();i++){
                edge& e=E[G[y][i]];
                if(dis[e.to]>dis[y]+e.dist){
                    dis[e.to]=dis[y]+e.dist;
                    Q.push(make_pair(dis[e.to],e.to));
                }
            }
        }
    }
};

signed main(){
    freopen("P3371.in","r",stdin);
    dij D;
    int N=read(),M=read(),st=read();
    D.init(N);
    for(int i=1;i<=M;i++){
        int x=read()-1,y=read()-1,w=read();
        D.add_e(x,y,w);
    }
    D.do_dij(st-1);
    for(int i=0;i<N;i++){
        printf("%d ",D.dis[i]);
    }
    return 0;
}