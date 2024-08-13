#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1ll<<60;
const int maxn=2e5+5;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int F[maxn],a[maxn];
void solve(){
    int N=read(),ans=-INF;
    for(int i=1;i<=N;i++) F[i]=a[i]=read();
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            int flg=1;
            for(int k=i+1;k<=j;k++)
                if((a[k]&1)^(a[k-1]&1)==0) {flg=0;break;}
            if(flg==0)continue;
            int now=0;
            for(int k=i;k<=j;k++) now+=a[k]; 
            ans=max(ans,now);
        }
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("C.in","r",stdin);
    freopen("C0.out","w",stdout);
    int T=read();
    while(T--)solve();
    return 0;
}