#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll n, k, v[MAXN], w[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> v[i] >> w[i];
    }
    ll ans = 0, dqb = (1ll << 31) - 1;;
    for(ll i = 30; i >= 0; i --){
        ll try_ans = ans | (1 << i);
        ll pp = dqb;
        for(int j = 1; j <= n; j ++){
            if(w[j] & (1 << i)){
                pp &= v[j];
            }
        }
        if(pp <= k) ans = try_ans;
    }
    cout << ans << endl;
    return 0;
}