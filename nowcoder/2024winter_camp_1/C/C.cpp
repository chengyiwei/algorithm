#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int t[maxn],s[maxn],q[maxn],p[maxn];
signed main(){
    freopen("C.in","r",stdin);
    int n,Q,tc; scanf("%lld%lld%lld",&n,&Q,&tc);
    for(int i=1;i<=n;i++) scanf("%lld",&t[i]);
    for(int i=1;i<=Q;i++) scanf("%lld",&q[i]);
    sort(t+1,t+n+1);
    for(int i=1;i<=n;i++) s[i] = s[i-1]+t[i];
    for(int i=1;i<=n+1;i++){ //插在 i 之前
        p[i] = tc * (n-i+1);
    }
    for(int i=1;i<=Q;i++){
        int l=1,r=n+1;
        while(l<=r){
            int mid = (l+r)>>1;
            if(p[mid] <= q[i]) r = mid-1;
            else l = mid+1;
        }
        int ans = s[l-1] + tc;
        printf("%lld\n",ans);
    }
    return 0;
}