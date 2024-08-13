#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=150005;
const int INF=1ll<<60;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int a[maxn],s[maxn];
void solve(){
    int N=read();
    for(int i=1;i<=N;i++) a[i]=read(); 
    for(int i=1;i<=N;i++) s[i]=s[i-1]+a[i];
    int ans=0;
    for(int k=1;k<=N;k++)if(N%k==0){
        int Max=-INF,Min=INF;
        for(int j=1;j<=N;j+=k){
            int sum=s[j+k-1]-s[j-1];
            Max=max(Max,sum);Min=min(Min,sum);
        }
        ans=max(ans,Max-Min);
    }
    printf("%lld\n",ans);
}
signed main(){
    // freopen("B.in","r",stdin);
    int T=read();
    while(T--)solve();
    return 0;
}