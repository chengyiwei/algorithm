#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=15;
int a[maxn];
int Fac[maxn];
void solve(){
    int n,k;
    scanf("%lld%lld",&n,&k); k++;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int ans=0;
    for(int i=2;i<=n;i++){
        int now=min(k,Fac[a[i]-a[i-1]]-1);
        ans+=now*Fac[a[i-1]];
        k-=now;
    }
    if(k) ans+=Fac[a[n]]*k;
    printf("%lld\n",ans);
}
signed main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    Fac[0]=1;
    for(int i=1;i<=10;i++) Fac[i]=Fac[i-1]*10;
    int T;scanf("%lld",&T);
    while(T--) solve();
    return 0;
}