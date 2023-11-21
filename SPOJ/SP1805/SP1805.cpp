#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;
int N,a[maxn];
int L[maxn],R[maxn];
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    while(scanf("%d",&N)!=EOF&&N){
        LL ans=0;
        for(int i=1;i<=N;i++) scanf("%d",&a[i]),L[i]=R[i]=i;
        for(int i=1;i<=N;i++) 
            while(L[i]>1&&a[i]<=a[L[i]-1]) L[i]=L[L[i]-1];
        for(int i=N;i;i--)
            while(R[i]<N&&a[i]<=a[R[i]+1]) R[i]=R[R[i]+1];
        for(int i=1;i<=N;i++)
            ans=max(ans,(LL)(R[i]-L[i]+1)*a[i]);
        printf("%lld\n",ans);
    }
    return 0;
}