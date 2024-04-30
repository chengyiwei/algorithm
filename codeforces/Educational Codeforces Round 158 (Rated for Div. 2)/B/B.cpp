#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans=0;
const int maxn=2e5+5;
int a[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
void solve(){
    int N=read();ans=0;
    for(int i=1;i<=N;i++) a[i]=read();
    a[0]=1;
    for(int i=1;i<=N;i++){
        if(a[i-1]<a[i]) ans+=a[i]-a[i-1];
    }
    printf("%lld\n",ans);
}
int main(){
    // freopen("B.in","r",stdin);
    int T=read();
    while(T--)solve();
}