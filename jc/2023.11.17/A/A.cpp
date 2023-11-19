#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5,maxe=maxn*2;
int N,M;

int son[maxe],nxt[maxe],lnk[maxn],cnt,w[maxe];

inline void add_e(int x,int y,int z){
    son[++cnt]=y;nxt[cnt]=lnk[x];lnk[x]=cnt;w[cnt]=z;
}

int vis[maxn];
bool dfs(int x,int top){
    vis[x]=1;
    if(x==N) return 1;
    for(int j=lnk[x];j;j=nxt[j])if(w[j]<=top){
        if(!vis[son[j]]) {
            if(dfs(son[j],top)) return 1;
        }
    }
    return 0;
}
bool check(int top){
    memset(vis,0,sizeof vis);
    return dfs(1,top);
}
signed main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%lld%lld",&N,&M);
    for(int i=1;i<=M;i++) {
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        add_e(x,y,z);add_e(y,x,z);
    }
    int L=0,R=1e4,ans=-1;
    while(L<=R){
        int mid=(L+R)/2;
        if(check(mid)) ans=mid,R=mid-1;
        else L=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}