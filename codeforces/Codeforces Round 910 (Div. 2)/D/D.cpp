#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
const LL INF=1ll<<60;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
struct Line{
    LL L,R;
}L[maxn];
inline void solve(){
    int N=read();
    LL ans=0;
    for(int i=1;i<=N;i++) L[i].L=read();
    for(int i=1;i<=N;i++) L[i].R=read();
    for(int i=1;i<=N;i++) {
        if(L[i].L>L[i].R) swap(L[i].L,L[i].R);
        ans+=L[i].R-L[i].L;
    }
    LL MaxL=-INF,MinR=INF;
    for(int i=1;i<=N;i++){
        MaxL=max(MaxL,L[i].L);
        MinR=min(MinR,L[i].R);
    }
    printf("%lld\n",ans+max((MaxL-MinR)*2,0ll));
    return ;
}
int main(){
    // freopen("D.in","r",stdin);
    // freopen("D.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}