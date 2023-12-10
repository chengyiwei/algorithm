#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int long long
const LL TT=998244353;
const int INF=1ll<<60;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int ksm(int a,int b){
    int ret=1;
    while(b){
        if(b&1) ret=ret*a%TT;
        a=a*a%TT;
        b>>=1;
    }
    return ret;
}

signed main(){
    freopen("C.in","r",stdin);
    int N=read(),Q=read();
    for(int i=1;i<=Q;i++){
        int x=read(),y=read();
        int op=x>>y&1,pos,ans=0,flg=0;
        for(pos=y;pos<N;pos++){
            if(pos>60) {
                flg=1;
                ans=ksm(2,N)-1;
                ans=(ans+TT)%TT;
                break;
            }
            if((x>>pos&1)==op) 
                ans=(ans+(1ll<<pos))%TT;
            else break;
        }
        if(!flg){
            for(pos=y-1;pos>=0;pos--){
                ans=(ans+(1ll<<pos))%TT;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}