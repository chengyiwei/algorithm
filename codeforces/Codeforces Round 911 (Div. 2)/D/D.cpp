#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=105;
int a[maxn];
LL num[maxn],up[maxn];
LL g[maxn],sum_p[maxn];
void solve(){
    int N=read(),top=0;
    LL ans=0;
    for(int i=1;i<=N;i++) {a[i]=read(),num[a[i]]++;top=max(top,a[i]);}
    for(int i=top;i;i--)    
        up[i]=up[i+1]+num[i];
    for(int k=top;k;k--){
        for(int i=1;i*k<=top;i++)
        for(int j=i+1;j*k<=top;j++){
            if(__gcd(i,j)!=1)continue;
            g[k]+=k*num[i*k]*num[j*k]*(up[j*k]);
        }
        g[k]+=(num[k]-1)*(num[k])/2*up[k];
        // for(int j=2;j*k<=top;j++)
        //     g[k]-=g[j*k];
    }
    for(int k=1;k<=top;k++){
        ans+=g[k];
    }
    printf("%lld\n",ans);
    return ;
}
int main(){
    freopen("D.in","r",stdin);
    int T=read();
    while(T--) solve();
}