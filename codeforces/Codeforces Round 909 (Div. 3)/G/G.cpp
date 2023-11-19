#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxe=maxn*2;
int id[maxn],N,M;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
struct Link{
    int x,y;
}L[maxn];
struct Query{
    int L,R,x,ans,id;
    Query(int L=0,int R=0,int x=0,int id):L(L),R(R),x(x),id(id){ans=0;}
};
int lnk[maxn],nxt[maxe],son[maxe],cnt;
inline void add_e(int x,int y){
    son[++cnt]=y;nxt[cnt]=lnk[x];lnk[x]=cnt;
}
vector<Query> Q[maxn];

int c[maxn];
void add_x(int x,int data){
    for(int i=x;i<=N;i+=i&-i) c[x]+=data;
}
int get_x(int x){
    if(x==0)return 0;
    int ret=0;
    for(int i=x;i;i-=i&-i) ret+=c[x];
    return ret;
}

bool vis[maxn];
void dfs(int x){
    vis[x]=1;
    
    for(int j=lnk[x];j;j=nxt[j])
}
void solve(){
    N=read(),M=read();
    for(int i=1;i<N;i++){L[i].x=read(),L[i].y=read();}
    for(int i=1;i<=N;i++){
        int now=read();
        id[now]=i;
    }
    for(int i=1;i<=N;i++){
        add_e(id[L[i].x],id[L[i].y]);
        add_e(id[L[i].y],id[L[i].x]);
    }
    for(int i=1;i<=M;i++){
        int L=read(),R=read(),x=id[read()];
        Q[x].push_back(Query(L,R,x,i));
    }
    
    dfs(id[1]);

}
int main(){
    freopen("F.in","r",stdin);
    int T=read();
    while(T--) solve();
    return 0;
}