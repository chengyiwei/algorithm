#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()

void solve(){
    int n,m; cin>>n>>m;
    vector<vector<ll>> w(n+1,vector<ll>(m+1));
    vector<vector<ll>> dp(n+1,vector<ll>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>w[i][j];
    }
    dp[1][1] = w[1][1];
    vector<int> d;
    ll tmp = __gcd(w[1][1],w[n][m]);
    for(int i=1;i<=tmp/i;i++){
        if(tmp%i==0){
            d.push_back(i);
            if(tmp/i!=i)  d.push_back(tmp/i);
        }
    }
    sort(all(d));
    reverse(all(d));
    ll ans = 0;
    for(auto it:d){
        dp[1][1] = it;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i>1){
                    tmp = __gcd(w[i][j],dp[i-1][j]);
                    if(tmp>=it && tmp%it==0 && dp[i-1][j]) dp[i][j] = max(dp[i][j],tmp);
                }
                if(j>1){
                    tmp = __gcd(w[i][j],dp[i][j-1]);
                    if(tmp>=it && (tmp%it==0) && dp[i][j-1]) dp[i][j] = max(dp[i][j],tmp);
                }
            }
        }
 
        if(dp[n][m]){
            cout<<it<<endl; return;
        }
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) dp[i][j] = 0;
        }       
    }
}

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("G0.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}