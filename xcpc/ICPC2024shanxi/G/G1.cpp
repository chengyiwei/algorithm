#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 5;
ll n, x, nums[22], dp[22][2][2];
ll dfs(ll pos, bool limit, bool ok){
    if(pos == 0 && ok) return 1;
    if(~dp[pos][limit][ok]) return dp[pos][limit][ok];
    ll mx = limit ? nums[pos] : 9;
    ll sum = 0;
    for(int i = 0; i <= mx; i ++){
        sum += dfs(pos - 1, limit && i == mx, ok && (i != x));
    }
    // cout << pos << " " << limit << " " << sum << endl;
    return dp[pos][limit][ok] = sum;
}
void solve(){
    cin >> n >> x;
    memset(dp, -1, sizeof dp);
    ll dq = n, cnt = 0;
    while(dq){
        nums[++ cnt] = dq % 10;
        dq /= 10;
    }
    cout << dfs(cnt, 1, 1) << endl;
}
int main(){
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}