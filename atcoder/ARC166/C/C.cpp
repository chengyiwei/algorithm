#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e6+5;
const LL TT = 998244353;
int T;
LL Fac[maxn],H,W,F[maxn],ans;
inline int read(){
    int ret = 0, f = 1;char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch=getchar();}
    while(ch>='0'&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return ret;
}
LL qpow(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1) ret=ret*a%TT;
        a=a*a%TT;
        b>>=1;
    }
    return ret;
}
int main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    T=read();

    Fac[1]=1;Fac[2]=2;
    for(int i=3;i<maxn;i++)
        Fac[i]=(Fac[i-1]+Fac[i-2])%TT;
    F[0]=1;
    for(int i=2;i<maxn;i+=2)
        F[i]=(F[i-2]*Fac[i])%TT;
    while(T--){
        H=read();W=read();
        if(H>W) swap(H,W);
        ans = qpow(Fac[H*2+1],W-H)*F[H*2]%TT*F[H*2]%TT;
        printf("%lld\n",ans);
    }
    return 0;
}