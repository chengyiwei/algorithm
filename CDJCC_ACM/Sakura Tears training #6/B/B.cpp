#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 998244353;
int main() {
    // freopen ("B.in", "r", stdin);
    ll N, K; cin >> N >> K;
    vector<ll> A(N + 1, 0), sum(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> A[i], sum[i] = sum[i - 1] + A[i];
    
    vector<ll> dp(N + 1, 0); dp[0] = 1;

    ll sum_dp = 1;
    map<ll, ll> mp;
    mp[0] = 1ll;
    for (int i = 1; i <= N; i++) {
        dp[i] = sum_dp;
        dp[i] = (dp[i] - mp[sum[i] - K] + TT) % TT;
        sum_dp = (sum_dp + dp[i]) % TT;
        mp[sum[i]] = (mp[sum[i]] + dp[i]) % TT;
    }
    // for (int i = 1; i <= N; i++)
    //     cout << dp[i] << " ";
    cout << dp[N] << endl;
    return 0;
}