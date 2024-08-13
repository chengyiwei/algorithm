#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;

struct node{
    LL x,y;
}a[maxn];

void solve(){
    int n; scanf("%d",&n); LL m; scanf("%lld",&m);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,[](node a,node b){return a.x < b.x;});
    LL now_p = 0,ans = m;
    for(int i=1;i<=n;i++){
        now_p += a[i].y;
        if(now_p + m >= a[i].x){
            LL tmp = m + now_p;
            ans = max(ans,tmp);
        }
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("G.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--) solve();
}