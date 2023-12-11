#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

struct Edge{
    int from,to,w;
    Edge(int x,int y,int z): from(x),to(y),w(z){}
};
vector<Edge> edges;
vector<vector<int> > G; 
int n,m;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

void add_e(int x,int y,int z){
    edges.push_back(Edge(x,y,z));
    G[x].push_back(edges.size()-1);
}

vector<int> dis,vis,num;
bool spfa(){
    dis.resize(n+1,INF);vis.resize(n+1,0);num.resize(n+1,0);
    queue<int> Q;
    int st=0;dis[st]=1;vis[st]=1;num[st]=0;Q.push(st);
    while(!Q.empty()){
        int u=Q.front();Q.pop();vis[u]=0;
        for(int i=0;i<G[u].size();i++){
            Edge& e=edges[G[u][i]];
            if(dis[e.to]>dis[u]+e.w){
                dis[e.to]=dis[u]+e.w; num[e.to]=num[u]+1;
                if(num[e.to]>n) return 0; // 判负环原理是入队次数 > n
                if(!vis[e.to]){vis[e.to]=1;Q.push(e.to);}
            }
        }
    }
    return 1;
}

int main(){
    freopen("P5960.in","r",stdin);
    scanf("%d%d",&n,&m);
    G.resize(n+1,vector<int>());
    for(int i=1;i<=m;i++){
        int x,y,c;scanf("%d%d%d",&x,&y,&c);
        add_e(y,x,c);
    }
    for(int i=1;i<=n;i++) add_e(0,i,0);
    if(spfa()){ //如果无负环
        for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    }
    else printf("NO\n");
    return 0;
}