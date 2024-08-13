#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT=998244353;
const int maxn=1e6+5;

LL read(){
    LL ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

LL n,m,a[maxn];
LL qsm(LL a,LL b=TT-2){
    LL ret=1;
    while(b){if(b&1) ret=ret*a%TT;a=a*a%TT;b>>=1;}
    return ret;
}


int main(){
    freopen("H.in","r",stdin);
    LL n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    LL E=1,ans=0;
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++){
        ans=(ans+a[i]*E%TT)%TT;
        E=(E*(m-1))%TT;E=E*qsm(m)%TT;
    }
    cout<<ans<<endl;
    return 0;
}