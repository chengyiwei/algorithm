#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int main(){
    freopen("D.in","r",stdin);
    int n;scanf("%d",&n);int ans=0;
    vector<int> a(n+1,0),L(n+1,INF),R(n+1,INF);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    L[1]=1;
    for(int i=2;i<=n;i++)
        L[i]=min(L[i-1]+1,a[i]);
    R[n]=1;
    for(int i=n-1;i>=1;i--)
        R[i]=min(R[i+1]+1,a[i]);
    for(int i=1;i<=n;i++)
        ans=max(ans,min(L[i],R[i]));
    printf("%d\n",ans);
    return 0;
}