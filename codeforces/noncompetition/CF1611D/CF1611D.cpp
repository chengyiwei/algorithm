#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

int T,O;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int fa[maxn],p[maxn];

int root,ans[maxn],dis[maxn];

void solve(){
    int N=read();
    for(int i=1;i<=N;i++){
        fa[i]=read();
        if(fa[i]==i){root=i;continue;}
    }
    for(int i=1;i<=N;i++)p[i]=read();
    if(p[1]!=root) {printf("-1\n");return ;}
    for(int i=2;i<=N;i++){
        if(fa[p[i]]!=root&&dis[fa[p[i]]]==0) {printf("-1\n");return ;}
        ans[p[i]]=dis[p[i-1]]-dis[fa[p[i]]]+1;
        dis[p[i]]=dis[fa[p[i]]]+ans[p[i]];
    }
    for(int i=1;i<=N;i++)
        printf("%d ",ans[i]);
    printf("\n");
    return ;
}

int main(){
    // freopen("CF1611D.in","r",stdin);
    T=read();
    while(T--){
        memset(ans,0,sizeof ans);
        memset(dis,0,sizeof dis);
        solve();
    }
    return 0;
}