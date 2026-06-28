#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 1e9 + 7;
ll x, y, z;

vector<int> get_fac (ll x) {
    vector<int> res;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x && i != 1)
                res.push_back(x / i);
        }
    }
    sort (res.begin(), res.end());
    return res;
}

int main() {
    freopen ("B.in", "r", stdin);
    freopen ("B0.out","w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    ll ans = 0;
    cin >> x >> y >> z;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            ans += a[i] * a[j] * ((x * __gcd(a[i], a[j]) + y) / z) ;
            ans %= TT;
        }
    cout << ans << endl;
    return 0;
}