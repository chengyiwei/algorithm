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
    int L,R,ans,qL,qR,id,num;
    Query(){ans=0;num=0;}
    // Query(int L=0,int R=0,int ql=0,int id):L(L),R(R),x(x),id(id){ans=0;}
};
int lnk[maxn],nxt[maxe],son[maxe],cnt;
inline void add_e(int x,int y){
    son[++cnt]=y;nxt[cnt]=lnk[x];lnk[x]=cnt;
}

Query Q[maxn];
bool vis[maxn];
int tin[maxn],tout[maxn],timer;
void dfs(int x,int fa){
    tin[x]=timer++;
    for(int j=lnk[x];j;j=nxt[j]){
        if(son[j]!=fa) dfs(son[j],x);
    }
    tout[x]=timer;
}

// bool cmp(Query A,Query B){
//     return A.L=
// }
void solve(){
    N=read(),M=read();
    for(int i=1;i<N;i++){
        int x=read(),y=read();
        add_e(x,y);add_e(y,x);
    }
    for(int i=1;i<=N;i++){p[i]=read();}
    dfs(1);
    for(int i=1;i<=M;i++){
        int L=read(),R=read(),x=read();
        Q[i].L=L,Q[i].R=R,Q[i].id=i,Q[i].qL=tin[x],Q[i].R=tout[x];
    }

    int now_L=0,now_R=0;
    for(int i=1;i<=M;i++){
        while(now_L<Q[i].L) del(now_L++);
    }

}
int main(){
    freopen("F.in","r",stdin);
    int T=read();
    while(T--) solve();
    return 0;
}