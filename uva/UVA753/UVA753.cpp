#include<bits/stdc++.h>
using namespace std;
int N,M,K;
const int maxn=405,INF=1<<29;
bool G[maxn][maxn];
int cnt;
map<string,int> mp;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int get(string x){
    if(mp.find(x)==mp.end())
        mp[x]=++cnt;
    return mp[x];
}

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
        for(int i=1;i<=n;i++) G[i].clear();
        edges.clear();
    }

    void add_e(int from,int to,int cap){
        // printf("%d %d %d\n",from,to,cap);
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

void solve(){
    mp.clear();cnt=0;
    N=read();
    vector<int> A(N+1);
    for(int i=1;i<=N;i++){
        string now;cin>>now;A[i]=get(now);
    }
    M=read();
    vector<int> B(M+1);
    for(int i=1;i<=M;i++){
        string now;cin>>now;cin>>now;B[i]=get(now);
    }
    memset(G,0,sizeof G);
    K=read();
    for(int i=1;i<=K;i++){
        string X,Y;
        cin>>X>>Y;
        G[get(X)][get(Y)]=1;
    }

    for(int k=1;k<=cnt;k++)
    for(int i=1;i<=cnt;i++)
    for(int j=1;j<=cnt;j++){
        G[i][j]|=(G[i][k]&G[k][j]);
    }

    Dinic F;
    F.init(cnt+2);
    int st=cnt+1,en=cnt+2;
    for(int i=1;i<=M;i++)
        F.add_e(st,B[i],1);
    for(int i=1;i<=N;i++)
        F.add_e(A[i],en,1);
    for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++){
        if(A[i]==B[j]) continue;
        if(G[B[j]][A[i]]){
            F.add_e(B[j],A[i],INF);
        }
    }
    
    cout<<M-F.Maxflow(st,en);

}
int main(){
    freopen("UVA753.in","r",stdin);
    freopen("UVA753.out","w",stdout);
    int T=read();
    while(T--){
        solve();
        if(T) printf("\n\n");
    }
    printf("\n");
    return 0;
}