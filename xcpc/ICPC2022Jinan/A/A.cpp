#include<bits/stdc++.h>
using namespace std;
const int INF=1<<30;
typedef long long LL;
void solve(){
    LL ans=INF;
    int n,m;scanf("%d%d",&n,&m);
    vector<int> a(n+1);
    set<int> G;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);int x=a[i];
        while(x){
            G.insert(x);
            x>>=1;
        }
    }
    for(auto k:G){
        int x=k;
        vector<int> f(n+1,INF);
        for(int i=1;i<=n;i++){
            int y=a[i],cnt=0;
            while(y){
                f[i]=min(f[i],cnt+abs(x-y));
                y>>=1;cnt++;
            }
        }
        sort(f.begin()+1,f.begin()+1+n);
        LL sum=0;
        for(int i=1;i<=n-m;i++)
            sum+=f[i];
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("A.in","r",stdin);
    int T;scanf("%d",&T);
    while(T--) solve();
    return 0;
}