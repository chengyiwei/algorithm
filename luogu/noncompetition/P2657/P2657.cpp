#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
int dp[maxn][maxn],num[maxn];

int dfs(int pos, int last, bool lead, bool limit){
    int ans = 0;
    if(pos == 0) return 1;
    if(!lead && !limit && dp[pos][last]!=-1) return dp[pos][last];
    int up = (limit ? num[pos] : 9);
    for(int i=0;i<=up;i++){
        if(abs(i-last) < 2) continue;
        if(lead && i==0)
            ans += dfs(pos-1, -2, true, limit && i==up);  //前面的前导零不算 0 
        else
            ans += dfs(pos-1, i, false, limit && i==up);
    }
    if(!lead && !limit) dp[pos][last] = ans;
    return ans;
}

int solve(int x){
    int len = 0;
    while(x){
        num[++len] = x%10;
        x/=10;
    }
    memset(dp,-1,sizeof dp);
    return dfs(len,-2,true,true);
}

int main(){
    int a,b; cin>>a>>b;
    cout<<solve(b)-solve(a-1)<<endl;
    return 0;
}