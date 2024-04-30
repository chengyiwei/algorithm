#include<bits/stdc++.h>
using namespace std;
const int maxn=15,INF=1<<30;

struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct EdmondsKarp{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn];  //起点到 i 的可改进量
    int p[maxn];

    void init(int n){
        this->n=n;
        for(int i=1;i<=n;i++) G[i].clear();
        edges.clear();
    }

    void add_e(int from,int to,int cap){
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    int Maxflow(int s,int t){
        int flow=0;
        for(;;){
            memset(a,0,sizeof a);
            queue<int> Q;
            Q.push(s);
            a[s]=INF;
            while(!Q.empty()){
                int x=Q.front();Q.pop();
                for(int i=0;i<G[x].size();i++){
                    Edge& e=edges[G[x][i]];
                    if(!a[e.to]&&e.cap>e.flow){ //如果 e.to 没有遍历过并且有残余流量
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        Q.push(e.to);
                    }
                }
                if(a[t]) break;//发现了一条路径
            }
            if(!a[t]) break; //若没有可行路径 跳出循环
            for(int u=t;u!=s;u=edges[p[u]].from){
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};

int main(){
    freopen("")
    int N,M,S,T;
    scanf("%d%d%d%d",&N,&M,&S,&T);
    EdmondsKarp A;
    A.init(N);
    for(int i=1;i<=M;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        A.add_e(x,y,w);
    }
    printf("%d\n",A.Maxflow(S,T));
    return 0;
}