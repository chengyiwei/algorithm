#include<bits/stdc++.h>
using namespace std;
const int maxn=250005;
typedef long long LL;
LL a[maxn],ans;
int vis[maxn],p[maxn];
int main(){
    freopen("A.in","r",stdin);
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=N;i++){
        scanf("%d",&p[i]);
        vis[i]++,vis[p[i]]++;
    }
    for(int i=2;i<=N;i++){
        if(vis[i]==1)
            ans+=a[i];
    }
    if(ans>0)
        printf("+\n");
    else if(ans<0)
        printf("-\n");
    else 
        printf("0\n");
}