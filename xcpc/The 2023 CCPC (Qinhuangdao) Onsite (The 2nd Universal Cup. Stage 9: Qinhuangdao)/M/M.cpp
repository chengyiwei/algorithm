#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const ll MAXN = 5e3 + 5;
const ll MOD = 998244353;
ll fastPow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll n, f[MAXN], flag[MAXN];
vector<ll> mp[MAXN];
ll M(ll x){
    return (x % MOD + MOD) % MOD;
}
void dfs(ll idx, ll fa, ll dep, vector<ll> &a){
    if(idx == fa){
        for(auto it : mp[idx]){
            if(it == fa) continue;
            dfs(it, idx, dep + 1, a);
        }
    }
    if(flag[idx]){
        f[idx] = M(f[idx] - dep * 2);
        
    }
    else{
        a.push_back(dep);
        return;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        f[i] = 1;
    }
    for(int i = 1; i < n; i ++){
        ll x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for(int i = 1; i < n; i ++){
        ll x; cin >> x;
        vector<ll> a;
        flag[x] = 1;
        dfs(x, -1, 0, a);
        a.push_back(0);
        ll as = a.size();
        vector<ll> b(as);
        for(int i = a.size() - 2; i >= 0; i --){
            b[i] = M(b[i + 1] + a[i]);
        }
        ll sum = 0;
        for(int i = 0; i < a.size() - 2; i ++){
            sum = M(sum + M( M( M((as - i - 2)) * a[i]) + b[i + 1]));
        }
        sum = M(2 * sum);
        f[x] = sum == 0 ? 1 : sum;
        // cout << "   " << x << " : " << f[x] << "\n";
        ll ans = 1;
        for(int i = 1; i <= n; i ++){
            ans = M(ans * f[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}