#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=1ll<<60;
vector<LL> a;
void solve(){
    int n,k;scanf("%d%d",&n,&k); a.resize(n);
    LL ans=INF;
    for(int i=0;i<n;i++) {scanf("%lld",&a[i]);ans=min(ans,a[i]);}
    if(k>=3) {printf("0\n");return ;}
    sort(a.begin(),a.end());
    if(k==1){
        for(int i=1;i<n;i++)
            ans=min(ans,a[i]-a[i-1]);
        printf("%lld\n",ans);
        return ;
    }

    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
        LL now=abs(a[j]-a[i]);
        ans=min(ans,now);
        auto it=upper_bound(a.begin(),a.end(),now);
        if(it!=a.end())ans=min(ans,abs((*it)-now));
        if(it!=a.begin()){
            --it;
            ans=min(ans,abs((*it)-now));
        }
    }
    printf("%lld\n",ans);
    return ;
}
int main(){
    freopen("C.in","r",stdin);
    int T;scanf("%d",&T);
    while(T--) solve();
    return 0;
}