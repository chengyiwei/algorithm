#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;scanf("%d",&n);
    double ans=n;
    vector<int> a(n+1);
    vector<double> p(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {
        int x;scanf("%d",&x);
        p[i]=(double)x/100000;
    }
    for(int i=1;i<=n;i++){
        if(p[i] == 0) continue;
        double now=(i-a[i])/p[i]+a[i];
        ans=min(ans,now);
    }
    printf("%.12lf\n",ans);
}
int main(){
    freopen("I.in","r",stdin);
    int T;scanf("%d",&T);
    while(T--) solve();
}