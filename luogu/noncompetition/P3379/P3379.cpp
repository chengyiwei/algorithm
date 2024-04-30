#include<bits/stdc++.h>
using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=5e5+5,maxe=maxn<<1;
int dep[maxn],F[maxn][25],M,S,N,vis[maxn];
int son[maxe],nxt[maxe],lnk[maxn],cnt;
void add_e(int x,int y){
    son[++cnt]=y;nxt[cnt]=lnk[x];lnk[x]=cnt;
}

void dfs(int x,int fa){
    vis[x]=1;
    F[x][0]=fa;dep[x]=dep[fa]+1;
    for(int i=1;i<=20;i++) F[x][i]=F[F[x][i-1]][i-1];
    for(int j=lnk[x];j;j=nxt[j])if(!vis[son[j]]){
        dfs(son[j],x);
    }
}

int lca(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    for(int i=20;i>=0;i--) 
        if(dep[F[b][i]]>=dep[a]) b=F[b][i];
    
    if(a==b) return a;
    for(int i=20;i>=0;i--)
        if(F[b][i]!=F[a][i]) 
            a=F[a][i],b=F[b][i];
    return F[a][0];
}
int main(){
    // freopen("P3379.in","r",stdin);
    N=read();M=read();S=read();
    for(int i=1;i<N;i++){
        int x=read(),y=read();
        add_e(x,y);
        add_e(y,x);
    }
    dfs(S,0);
    for(int i=1;i<=M;i++){
        int a=read(),b=read();
        printf("%d\n",lca(a,b));
    }
    return 0;
}