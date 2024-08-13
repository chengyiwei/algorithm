#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;
const LL INF=1e18;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
LL a[maxn],s[maxn];
LL ans=INF;
int main(){
    freopen("K.in","r",stdin);
    int n=read(),k=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=k;i<=n;i++){
        LL now=k*a[i]-(s[i]-s[i-k]);
        ans=min(ans,now);
    }
    printf("%lld\n",ans);
    return 0;
}