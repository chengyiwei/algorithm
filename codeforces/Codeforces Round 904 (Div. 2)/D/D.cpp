#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e6+5;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
LL C(LL x){
    return (x)*(x-1)>>1;
}
int N,vis[maxn];
LL ans,num,g[maxn],a[maxn],hsh[maxn],Max;
//g[i] 表示数字为 i 的时候，gcd(,) = i 的个数

int main(){
    // freopen("D.in","r",stdin);
    // freopen("D.out","w",stdout);
    int T=read();
    while(T--){
        ans=0;
        N=read();
        for(int i=1;i<=N;i++) vis[i]=hsh[i]=g[i]=0;
        for(int i=1;i<=N;i++)a[i]=read(),hsh[a[i]]++;
        Max=N;
        for(int i=Max;i;i--){
            num=0;
            for(int j=1;j*i<=Max;j++){
                num+=hsh[j*i];
            }
            g[i]+=C(num);
            for(int j=2;j*i<=Max;j++){
                g[i]-=g[i*j];
            }
        }
        for(int i=1;i<=Max;i++)if(hsh[i]){
            for(int j=1;j*i<=Max;j++)
                vis[i*j]=1;
        }
        for(int i=1;i<=Max;i++) 
            if(!vis[i])
                ans+=g[i];
        printf("%lld\n",ans);
    }
    return 0;
}