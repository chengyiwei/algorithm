#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 15;
LL num[maxn],now,dp[maxn][maxn];

LL dfs(int pos,int sum,bool lead,bool limit){
    LL ans = 0;
    if(pos == 0) return sum;
    if( !lead && !limit && dp[pos][sum]!=-1 ) return dp[pos][sum]; //记忆化搜索
    int up = limit ? num[pos] : 9; //这一位的最大值
    for(int i=0;i<=up;i++){
        if( i==0 && lead )
            ans += dfs(pos-1, sum, true, limit && i==up); //计算 000-099
        else if(i==now)
            ans += dfs(pos-1, sum+1, false, limit && i==up); //计算 x00-x99
        else if(i!=now)
            ans += dfs(pos-1, sum, false, limit && i==up); //计算其他
    }
    if(!lead && !limit) dp[pos][sum] = ans; //可以重复使用部分
    return ans;
}

LL solve(LL x){
    int len = 0;
    while(x){
        num[++len] = x%10;
        x/=10;
    }
    memset(dp,-1,sizeof dp);
    return dfs(len,0,true,true);
}

int main(){
    LL a,b; cin>>a>>b;
    for(int i=0;i<10;i++){
        now = i;
        cout<<solve(b)-solve(a-1)<<" ";
    }
    return 0;
}