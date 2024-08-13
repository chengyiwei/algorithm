#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL TT=998244353;
const int maxn=2e5+5;

inline LL read(){
    LL ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

LL N,M,ans=1;
string s;

LL qpow(LL a,LL b){//快速幂求逆元
    LL ret=1;
    while(b){
        if(b&1)ret=ret*a%TT;
        a=a*a%TT;
        b>>=1;
    }
    return ret;
}
int main(){
    // freopen("D.in","r",stdin);
    // freopen("D.out","w",stdout);
    N=read();M=read();
    cin>>s;
    s="  "+s;
    for(int i=N;i>=3;i--)
        if(s[i]=='?') ans=ans*(i-2)%TT;
    printf("%lld\n",s[2]=='?'?0:ans);
    while(M--){
        LL pos=read()+1;
        char ch=getchar();
        if(pos>=3&&s[pos]=='?')
            ans=ans*qpow(pos-2,TT-2)%TT;
        s[pos]=ch;
        if(pos>=3&&s[pos]=='?')
            ans=ans*(pos-2)%TT;
        printf("%lld\n",s[2]=='?'?0:ans);
    }
    return 0;
}