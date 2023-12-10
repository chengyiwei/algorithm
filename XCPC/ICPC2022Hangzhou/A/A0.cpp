#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL  exgcd(LL a,LL b,LL &x,LL &y){
    if(!b){x=1,y=0;return a;}
    LL d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}
int main(){
    freopen("A.in","r",stdin);
    LL N,M,sum=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        LL x;cin>>x;sum+=x;
    }
    LL a,b,x,y,k1,t;
    a=N,b=N*(N+1)/2;
    LL g1=__gcd(a,b),g2=__gcd(g1,M);
    LL ans=sum%g2;

    exgcd(g1,M,k1,t);
    k1*=((ans-sum)/g2)%M;
    k1%=M;

    exgcd(a,b,x,y);
    x*=k1,y*=k1;

    cout<<ans<<endl;
    cout<<(x%M+M)%M<<" "<<(y%M+M)%M<<endl;
    return 0;
}