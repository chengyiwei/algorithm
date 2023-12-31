#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=205,INF=1ll<<40;

struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct Dinic{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void add_e(int from,int to,int cap){
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    
    bool BFS(){
        memset(vis,0,sizeof vis);
        queue<int> Q;
        Q.push(s);d[s]=0;vis[s]=1;
        while(!Q.empty()){
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();i++){
                Edge &e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t]; //判断是否能走到 t
    }

    int DFS(int x,int a){ //a表示当前流到这个节点的流
        if(x==t||a==0) return a;
        int flow=0,f;
        for(int& i=cur[x];i<G[x].size();i++){ //当前弧优化
            Edge& e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }

    int Maxflow(int s,int t){
        this->s=s,this->t=t;
        int flow=0;
        while(BFS()){
            memset(cur,0,sizeof cur);
            flow+=DFS(s,INF);
        }
        return flow;
    }
};

signed main(){
    freopen("P3376.in","r",stdin);
    int N,M,S,T;
    scanf("%lld%lld%lld%lld",&N,&M,&S,&T);
    Dinic A;
    A.init(N);
    for(int i=1;i<=M;i++){
        int x,y,w;
        scanf("%lld%lld%lld",&x,&y,&w);
        A.add_e(x,y,w);
    }
    printf("%lld\n",A.Maxflow(S,T));
    return 0;
}