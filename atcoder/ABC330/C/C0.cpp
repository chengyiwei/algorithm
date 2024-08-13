#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e6+5;
LL a[maxn],tot,ans=2e12+10;
int main(){
    freopen("C.in","r",stdin);
    freopen("C0.out","w",stdout);
    LL D;
    cin>>D;
    for(LL i=1;i*i<D;i++)
    for(LL j=1;j*j<D;j++){
        ans=min(ans,abs(D-(i*i+j*j)));
    }
    printf("%lld\n",ans);
    return 0;
}