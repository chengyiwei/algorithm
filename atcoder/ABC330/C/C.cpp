#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e6+5;
LL a[maxn],tot,ans=2e12+10;
int main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    LL D;
    cin>>D;
    for(LL i=0;i*i<=D;i++)
        a[++tot]=i*i;
    LL pos=tot;
    for(int i=1;i<=tot;i++){ //D-(x2+y2)
        while(pos>0&&a[pos]+a[i]>D) pos--;
        if(pos<tot) ans=min(ans,a[pos+1]+a[i]-D);
        if(pos>0) ans=min(ans,D-(a[pos]+a[i]));
    }
    printf("%lld\n",ans);
    return 0;
}