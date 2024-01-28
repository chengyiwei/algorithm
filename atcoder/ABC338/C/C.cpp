#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;
signed main(){
    // freopen("C.in","r",stdin);
    // freopen("C.out","w",stdout);
    int n; scanf("%lld",&n);
    vector<int> a(n+1),b(n+1),q(n+1);
    for(int i=1;i<=n;i++) scanf("%lld",&q[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int ans = 0;
    for(int num_a=0;num_a<=1e6;num_a++){  // num_a 个 a
        int now_ans = INF;
        for(int j=1;j<=n;j++){
            if(num_a * a[j] > q[j]) {
                now_ans = -1;
                break;
            }
            int num_b;
            if(b[j] > 0) num_b = (q[j] - num_a*a[j]) / b[j];
            else num_b = INF;
            now_ans = min(now_ans, num_b + num_a);
        }
        if(now_ans != -1)
            ans = max(ans, now_ans);
    }
    printf("%lld\n",ans);
    return 0;
}