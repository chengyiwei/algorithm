#include<bits/stdc++.h>
using namespace std;
const int maxn=5e1+5,INF=1<<30,maxK=15;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int N,M,K;
int dis[maxn][maxK],vis[maxn][maxK];
int ans=INF;
struct State{
    int v,w,cnt;
    State(){}
    State(int v,int w,int cnt):v(v),w(w),cnt(cnt){}
    bool operator<(const State& B) const {return w>B.w;}
};

struct Edge{
    int from,to,w;
    Edge(int x,int y,int z):from(x),to(y),w(z){}
};

vector<Edge> edges;
vector<int> G[maxn];

void dij(int st){
    memset(dis,0x3f,sizeof dis);
    dis[st][0]=0;
    priority_queue<State> pq;
    pq.push(State(st,0,0));
    while(!pq.empty()){
        State now=pq.top();pq.pop();
        int u=now.v,now_cnt=now.cnt; //u表示现在拓展的节点，now_cnt表示层数
        if(vis[now.v][now_cnt]) continue;
        vis[now.v][now_cnt]=1;
        for(int i=0;i<G[u].size();i++){
            Edge& e=edges[G[u][i]];
            if(now_cnt<K&&dis[e.to][now_cnt+1]>dis[u][now_cnt]){
                dis[e.to][now_cnt+1]=dis[u][now_cnt];
                pq.push(State(e.to,dis[e.to][now_cnt+1],now_cnt+1));
            }
            if(dis[e.to][now_cnt]>dis[u][now_cnt]+e.w){
                dis[e.to][now_cnt]=dis[u][now_cnt]+e.w;
                pq.push(State(e.to,dis[e.to][now_cnt],now_cnt));
            }
        }
    }
}

void add_e(int x,int y,int z){
    edges.push_back(Edge(x,y,z));
    G[x].push_back(edges.size()-1);
}

int main(){
    freopen("P4568.in","r",stdin);
    freopen("P4568.out","w",stdout);
    N=read();M=read();K=read();
    int st=read()+1,ed=read()+1;
    for(int i=1;i<=M;i++){
        int x=read()+1,y=read()+1,w=read();
        add_e(x,y,w);add_e(y,x,w);
    }
    dij(st);
    for(int i=0;i<=K;i++)
        ans=min(ans,dis[ed][i]);
    printf("%d\n",ans);
    return 0;
}