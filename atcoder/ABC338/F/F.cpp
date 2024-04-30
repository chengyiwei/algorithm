#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1ll<<60;
int n,m,dp[1<<20][21];
int dist[21][21];
signed main(){
    for(int S=0;S<(1<<20);S++)
        for(int j=0;j<21;j++)
            dp[S][j] = INF;
    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
            dist[i][j] = INF;
    cin>>n>>m;
    while(m--){
        int x,y; cin>>x>>y; x--; y--;
        int z; cin>>z; dist[x][y] = min(dist[x][y],z);
    }

    //Floyd
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    for(int i=0;i<n;i++)
        dp[1<<i][i] = 0; //初始化
    
    for(int S=1;S<(1<<n);S++)
        for(int j=0;j<n;j++)
            if((S>>j)&1)  //S 集合中有 j
                for(int k=0;k<n;k++)
                    if((S^(1<<j))>>k&1)  //S-j 集合中有 k
                        dp[S][j] = min(dp[S][j],dp[S^(1<<j)][k]+dist[k][j]);
    
    int ans = 1e9;
    for(int i=0;i<n;i++)
        ans = min(ans,dp[(1<<n)-1][i]);
    if(ans == 1e9) cout<<"No"<<endl;
    else cout<<ans<<endl;
    return 0;
}