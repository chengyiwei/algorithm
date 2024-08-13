#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT = 1e9 + 7;
int main(){
    freopen("F.in","r",stdin);
    int n,m; scanf("%d%d",&n,&m);
    vector<LL> F(m+1); F[1]=1;
    LL lst, now =1;
    for(int i=n-1;i>=1;i--){
        for(int j=m;j;j--){
            F[j] = (F[j-1] + F[j] * j) % TT;
        }
        for(int j=1;j<=m;j++)
            printf("%d ",F[j]);
        printf("\n");
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",F[i]);
}