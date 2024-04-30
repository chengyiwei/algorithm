#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int w[maxn][maxn],c[maxn][maxn];
int dp[maxn];
int n,m;
int main(){
    freopen("1712.in","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF && m && n){
        for(int i=1;i<=n;i++)
            for(int k=1;k<=m;k++)
                scanf("%d",&w[i][k]),c[i][k]=k;
        
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=m;j>=0;j--)
                for(int k=1;k<=m;k++)
                    if(j>=c[i][k])
                        dp[j]=max(dp[j],dp[j-c[i][k]]+w[i][k]);
        printf("%d\n",dp[m]);
    }
    return 0;
}