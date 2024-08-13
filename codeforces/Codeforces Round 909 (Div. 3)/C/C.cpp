#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1ll<<60;
const int maxn=2e5+5;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int F[maxn],a[maxn];
void solve(){
    int N=read(),ans=-INF;
    if(N==1){int x=read();printf("%lld\n",x);return ;}
    for(int i=1;i<=N;i++) F[i]=a[i]=read(); ans=F[1];
    for(int i=2;i<=N;i++){
        if((a[i]&1)^(a[i-1]&1)) {
            F[i]=max(F[i],F[i-1]+a[i]);
        }
        ans=max(ans,F[i]);
    }
    
    printf("%lld\n",ans);
}
signed main(){
    // freopen("C.in","r",stdin);
    // freopen("C.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}