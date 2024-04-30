#include<bits/stdc++.h>
using namespace std;
void solve(){
    int c,d,h,w;scanf("%d%d%d%d",&c,&d,&h,&w);
    double ans = (2.0*w+4.0*w)*c/2.0;
    printf("%.6lf\n",ans);
}
int main(){
    int T;scanf("%d",&T);
    while(T--) solve();
}