#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;scanf("%d",&n);
    vector<int> a(n+1),b(n+1);
    vector<double> p(n+1);
    for(int i=1;i<=n;i++) scanf("%d%d%lf",&a[i],&b[i],&p[i]);
    double ans=0;
    vector<double> q(n+1);
    for(int i=1;i<=n;i++) q[i]=a[i]*(1-p[i])+p[i]*(a[i]+b[i]);
    sort(q.begin()+1,q.begin()+n+1);
    double now=0;
    for(int i=1;i<=n;i++) {
        now+=q[i];
        ans=ans+now;
    }
    printf("%.12lf\n",ans);
}
int main(){
    freopen("M.in","r",stdin);
    int T;scanf("%d",&T);
    while(T--) solve();
}