#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;

void solve(){
    int n; scanf("%d",&n);
    vector<LL> a(n+1);
    for(int i = 1; i <= n; i++)
        scanf("%lld",&a[i]);
    sort(a.begin() + 1, a.end());
    LL ans = 0; LL x_2 = a[1] * 2;
    for(int i = 1; i <= n; i++){
        if(a[i] > x_2) ans += x_2 * (n - i);
        else ans += a[i] * (n - i);
    }
    printf("%lld\n",ans * 4);
}

int main(){
    freopen("J.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--) solve();
    return 0;
}