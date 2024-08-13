#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
const int maxn=25;
int N;LL S,ans,a[maxn];
int nxt[maxn],s[maxn];
int F[maxn];
int DFS(int x) //x开始往后的值
{
    if(F[x]!=-1){
        return F[x];
    }
    if(nxt[x]>N) return F[x]=(N-x+1); 
    return F[x]=(nxt[x]-x)+DFS(nxt[x])+(N-nxt[x]+1);
}
signed main(){
    freopen("B.in","r",stdin);
    scanf("%lld%lld",&N,&S);
    for(int i=1;i<=N;i++) scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
    for(int i=1;i<=N;i++) F[i]=-1;
    int pos=1;
    for(int i=1;i<=N;i++){
        while(pos<=N&&s[pos]-s[i-1]<=S)
            pos++;
        nxt[i]=pos;
    }
    for(int i=1;i<=N;i++){
        ans+=DFS(i);
    }
    printf("%lld\n",ans);
    return 0;
}