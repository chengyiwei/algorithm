#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
int v[maxn],w[maxn];

void solve(){
    int n,C;  LL ans = 0;
    scanf("%d%d",&n,&C);
    for(int i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);

    for(int i=1;i<=n;i++){
        int flg = 1;
        for(int k=0;(1<<k)<=w[i];k++)
            if((w[i]>>k&1) && !(C>>k&1)){
                flg = 0;
                break;
            }
        if(flg) ans += v[i];
    }

    for(int j=0;(1<<j)<=C;j++){ //把第 j 位的 1 强制成 0 
        LL now_ans = 0;
        if(!((C>>j)&1)) continue;
        for(int i=1;i<=n;i++){
            int flg = 1;
            if((w[i]>>j)&1) continue;
            for(int k=j;(1<<k)<=w[i];k++)
                if((w[i]>>k&1) && !(C>>k&1)){
                    flg = 0;
                    break;
                }
            if(flg) now_ans += v[i];
        }
        ans = max(ans,now_ans);
    }
    
    printf("%lld\n",ans);
}

int main(){
    freopen("H.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--) solve();
    return 0;
}