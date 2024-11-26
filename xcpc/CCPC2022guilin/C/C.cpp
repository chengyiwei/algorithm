#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;
ll n, m, a[MAXN], f[MAXN], g[MAXN], sum, ans, tmp = 1, h[MAXN];
ll M(ll x){
    return (x % MOD + MOD) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += a[i]; sum = M(sum);
        h[0] += (n - i + 1) * a[i]; h[0] = M(h[0]);
    }

    g[1] = M(n); f[1] = M(2 * n + 1);
    for(ll i = 2; i <= m; i ++){
        g[i] = 4 * g[i - 1];
        f[i] = M((f[i - 1] << 1) + g[i]);
        g[i] = M(g[i]);
    }

    ll tmp = 1;
    for (int i = 1; i <= m; i++) {
        h[i] = M(h[i - 1] * 2) + M(M(tmp * n) * sum);
        h[i] = M(h[i]); tmp = M(tmp * 4);
    }
    ans = max(h[m], M(f[m] * sum));
    // cout << h[m] << " " << M(f[m] * sum) << '\n';

    cout << ans << "\n";
    return 0;
}