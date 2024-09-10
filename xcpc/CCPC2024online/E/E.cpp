#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll MOD = 998244353;
ll n, m;
ll fastPow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
ll M(ll x){
    return (x % MOD + MOD) % MOD;
}
int main(){
    // freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    ll ans1 = 1, ans2 = 1, cnt = 1;
    for(int i = 1; i <= m; i ++){
        if(cnt < n) cnt *= 26;
        ans1 += min(cnt, n);
        ans2 += M(M(1 - fastPow(M(1 - fastPow(fastPow(26, i), MOD - 2)), n)) * fastPow(26, i));
        ans1 = M(ans1);
        ans2 = M(ans2);
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}