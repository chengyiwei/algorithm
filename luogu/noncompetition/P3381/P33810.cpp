#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5005,INF=1<<30;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

struct Edge{
    int from,to,cap,flow,cost;
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w){}
};

struct Dinic{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int vis[maxn];
    int dis[maxn];
    int a[maxn];  //起点到 i 的可改进量
    int cur[maxn]; //当前弧
    

    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void add_e(int from,int to,int cap,int cost){
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool SPFA(){
        for(int i=1;i<=n;i++)dis[i]=INF;
        memset(vis,0,sizeof vis);
        queue<int> Q;
        Q.push(s);dis[s]=0;vis[s]=1;a[s]=INF;
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            vis[u]=0;
            for(int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if(e.cap-e.flow>0&&dis[e.to]>dis[u]+e.cost){
                    dis[e.to]=dis[u]+e.cost;
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!vis[e.to]){Q.push(e.to);vis[e.to]=1;}
                }
            }
        }
        if(dis[t]==INF) return false;
        return true;
    }
    
    int DFS(int u,int a){
        if(a==0||u==t) return a;
        vis[u]=1;
        int flow=0,cost=0,f;
        for(int& i=cur[u];i<G[u].size();i++){
            Edge &e=edges[G[u][i]];
            if(!vis[e.to] && dis[u]+e.cost==dis[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[u][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }

    int MincostMaxflow(int s,int t,LL& cost){
        this->s=s,this->t=t;
        int flow=0;
        while(SPFA()){
            memset(vis,0,sizeof vis);
            memset(cur,0,sizeof cur);
            int now_flow=DFS(s,INF);
            flow+=now_flow;
            cost+=dis[t]*now_flow;
        }
        return flow;
    }
};

int main(){
    freopen("P3381.in","r",stdin);
    int n,m,s,t;
    n=read();m=read();s=read();t=read();
    Dinic A;
    A.init(n);
    for(int i=0;i<m;i++){
        int x=read(),y=read(),c=read(),w=read();
        A.add_e(x,y,c,w);
    }
    LL cost=0;
    cout<< A.MincostMaxflow(s,t,cost) ;
    cout<<" "<<cost<<endl;
    return 0;
}