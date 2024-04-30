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
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        ans += a[i] * (i - 1);
    }
    printf("%lld\n",ans * 4);
}

int main(){
    freopen("I.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--) solve();
    return 0;
}