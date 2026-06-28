#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5,maxe=maxn*maxn;
int N,A,B,C,G[maxn][maxn];
int ans=1e18;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
struct AS{
    int lnk[maxn],nxt[maxe],son[maxe],w[maxe],cnt=0;
    AS(){
        memset(lnk,0,sizeof lnk);
        memset(nxt,0,sizeof nxt);
        memset(son,0,sizeof son);
        memset(w,0,sizeof w);
    }
    void add_e(int x,int y,int z){
        son[++cnt]=y;w[cnt]=z;nxt[cnt]=lnk[x];lnk[x]=cnt;
    }
    
    int dis[maxn],vis[maxn],Q[maxn],hed=0,til=1;
    void spfa(int x){
        memset(vis,0,sizeof vis);
        memset(dis,63,sizeof dis);
        dis[x]=0;vis[x]=1;Q[til]=x;
        while(hed!=til){
            hed=(hed+1)%maxn;vis[Q[hed]]=0;
            for(int j=lnk[Q[hed]];j;j=nxt[j]){
                if(dis[son[j]]>dis[Q[hed]]+w[j]){
                    dis[son[j]]=dis[Q[hed]]+w[j];
                    if(!vis[son[j]]){
                        til=(til+1)%maxn;
                        Q[til]=son[j];
                        vis[son[j]]=1;
                    }
                }
            }
        }
    }
    
}X,Y;
signed main(){
    freopen("E.in","r",stdin);
    N=read();A=read();B=read();C=read();
    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++){
        G[i][j]=read();
        X.add_e(i,j,G[i][j]*A);
        Y.add_e(j,i,G[i][j]*B+C);
    }
    X.spfa(1);
    Y.spfa(N);
    for(int i=1;i<=N;i++){
        ans=min(ans,X.dis[i]+Y.dis[i]);
    }
    printf("%lld\n",ans);
    return 0;
}