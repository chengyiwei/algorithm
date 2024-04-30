#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=3e5+5,INF=2e9;
int a[maxn],R[maxn],L[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    // freopen("D.in","r",stdin);
    int N=read();
    for(int i=1;i<=N;i++) a[i]=read();
    for(int i=1;i<=N;i++){
        int now=N-i+a[i];
        L[i]=max(L[i-1],now);
    }
    for(int i=N;i;i--){
        int now=i-1+a[i];
        R[i]=max(R[i+1],now);
    }
    int ans=INF;
    for(int i=1;i<=N;i++){
        int now=max(a[i],max(L[i-1],R[i+1]));
        ans=min(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}