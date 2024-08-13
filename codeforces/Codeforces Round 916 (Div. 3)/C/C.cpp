#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void solve(){
    int n,k;cin>>n>>k;
    LL ans=0,now,lst_max=0,lst_sum=0;
    vector<LL> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=min(n,k);i++){
        lst_max=max(lst_max,b[i]);
        lst_sum=lst_sum+a[i];
        now=lst_sum+(k-i)*lst_max;
        ans=max(ans,now);
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("C.in","r",stdin);
    int T;cin>>T;
    while(T--) solve();
}