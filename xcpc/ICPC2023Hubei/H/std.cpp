#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6+5;
const ll MOD = 998244353;
ll n, m, du[MAXN], sum;
ll M(ll x){
    return (x % MOD + MOD) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    freopen("in.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        ll x, y;
        cin >> x >> y;
        du[x] ++; du[y] ++;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = i; j <= n; j ++){
            sum = M(sum + M(M((du[i] ^ du[j]) * (du[i] | du[j])) * (du[i] & du[j])));
        }
    }
    cout << sum << endl;
    return 0;
}