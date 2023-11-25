#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
const int maxn=1e3+5;
int s[maxn],N,tmp[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
signed main(){
    freopen("E.in","r",stdin);
    N=read();
    int ans=0;
    for(int i=1;i<=N;i++) {
        s[i]=s[i-1]+read();
        if(s[i]>0) ans++;
    }
    for(int i=1;i<=N;i++)
    for(int j=i+1;j<=N;j++){
    	ans+=(s[j]-s[i]>0);
	}
    printf("%lld\n",ans);
    return 0;
}
