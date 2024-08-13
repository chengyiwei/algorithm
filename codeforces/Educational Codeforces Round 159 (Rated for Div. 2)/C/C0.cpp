#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
typedef long long LL;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int a[maxn],b[maxn];
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
void solve(){
    LL ans=0;
    int N=read();
    for(int i=1;i<=N;i++) a[i]=read();
    if(N==1){printf("1\n");return ;}
    sort(a+1,a+1+N,greater<int>());
    for(int i=1;i<=N;i++) a[i]-=a[N];
    int g=abs(a[2]-a[1]);
    for(int i=3;i<=N;i++){
        g=gcd(g,abs(a[i]-a[i-1]));
    }
    int flg=0;
    for(int i=1;i<=N;i++){
        b[i]=(a[1]-a[i])/g;
        ans+=b[i];
        if(flg==0&&b[i]!=i-1) {
            ans+=i-1;flg=1;
        }
    }
    if(!flg)ans+=N;
    printf("%lld\n",ans);
    return ;
}
signed main(){
    int T=read();
    while(T--) solve();
}