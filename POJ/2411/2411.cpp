#include<bits/stdc++.h>
using namespace std;
int n,dp[1<<20][21];
int dist[21][21];
int main(){
    memset(dp,0x3f,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>dist[i][j];
    dp[1][0] = 0; //开始集合中只有 0
    for(int S=1;S<(1<<n);S++)
        for(int j=0;j<n;j++)
            if((S>>j)&1)  //集合中有 j
                for(int k=0;k<n;k++)
                    if((S^(1<<j))>>k&1)
                        dp[S][j] = min(dp[S][j],dp[S^(1<<j)][k]+dist[k][j]);
    
    cout<<dp[(1<<n)-1][n-1]<<endl;
    return 0;
}