#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
void solve(){
    int n=read(),P=read(),l=read(),t=read(),m;
    int num_t=(n-1)/7+1,day_t=num_t/2;
    if(num_t*t+day_t*l>=P) { //都做任务
        m=P/(l+t*2)+(P%(l+t*2)!=0);
    }
    else{
        int P_=P-(num_t*t+day_t*l);
        m=day_t+P_/l+(P_%l!=0);
    }
    printf("%lld\n",n-m);
}
signed main(){
    freopen("B.in","r",stdin);
    int T=read();
    while(T--) solve();
}