#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
ll Tex, x, y, a0, a1, b, p0, p1;
ll fastPow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
ll M(ll x){
    return (x % MOD + MOD) % MOD;
}
ll calc(ll p, ll k){
    if (k < 0) return 0ll;
    ll fm = fastPow(M(1 - p), MOD - 2);
    ll fz = M(1 - fastPow(p, k + 1));
    return M(fz * fm);
}
ll f(ll x, ll y, ll px, ll py){
    if(y == 0) return 1;
    if(x == y) return p0 % MOD;
    ll g = x % y;
    ll k = (x - g) / y;
    return M(M(calc(py, k - 1) * px) + M(fastPow(py, k) * M(1 - f(y, x % y, py, px))));
}
void AC(){
    scanf("%lld%lld", &x, &y);
    scanf("%lld%lld%lld", &a0, &a1, &b);
    b = a0 + a1;
    p0 = fastPow(b, MOD - 2) * a0 % MOD;
    p1 = fastPow(b, MOD - 2) * a1 % MOD;
    printf("%lld", f(x, y, p0, p1));
    printf("\n");
}
int main(){
    // freopen ("G.in", "r", stdin);
    scanf("%lld", &Tex);
    while(Tex --) AC();
    return 0;
}