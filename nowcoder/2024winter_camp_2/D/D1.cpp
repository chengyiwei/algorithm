#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;

void solve(){
    int n, m, k; scanf("%d%d%d",&n,&m,&k); k = (n - k);
    vector<int> a(m + 1), b(m + 1);
    for(int i = 1; i <= m; i ++)
        scanf("%d%d",&a[i],&b[i]);
    vector<LL> F(n+1,INF);
    for(int i = 1; i <= m; i++){
        vector<int> vis(n +1, 0);
        for(int j = a[i], p = 0; vis[j] == 0; j = (j + a[i]) % n){
            vis[j] = 1; p++;
            F[j] = min(F[j], 1LL * b[i] * p);
        }
    }
    for(int p = 1; p <= 2; p ++){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n ; j++){     
                F[(i + j) % n] = min(F[(i + j) % n], F[i] + F[j]);
            }
    }
    LL ans = F[k] == INF ? -1 : F[k];
    printf("%lld\n",ans);
}

int main(){
    freopen("D.in","r",stdin);
    freopen("D1.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--) solve();
    return 0;
}