#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll TT = 998244353;

int main() {
    freopen ("F.in", "r", stdin);
    ll n, m;
    cin >> n >> m;
    ll num = m;
    vector<ll> fac, p;
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            p.push_back(i);
            ll val = 1;
            while (num % i == 0) {
                val *= i;
                num /= i;
            }
            fac.push_back(val);
        }
    }
    if (num > 1) {
        p.push_back(num);
        fac.push_back(num);
    }

    
    vector<ll> a(n + 1), cnt(1 << p.size(), 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ll val = 0;
        for (int j = 0; j < p.size(); j++) {
            if (a[i] % fac[j] == 0) {
                a[i] /= fac[j];
                if (a[i] % p[j] == 0) break;
                val |= 1 << j;
            }
            while (a[i] % p[j] == 0)
                a[i] /= p[j];
        }
        if (a[i] == 1)
            cnt[val] ++;
    }
    vector<ll> pw2(n + 1, 1);
    for (int i = 1; i <= n; i++)
        pw2[i] = pw2[i - 1] * 2 % TT;
    vector<ll> dp(1 << p.size(), 0);
    dp[0] = pw2[cnt[0]];
    for (int i = 1; i < (1 << p.size()); i++) {
        for (int j = (1 << p.size()) - 1; j >= 0; j--) {
            dp[i | j] += dp[j] * (pw2[cnt[i]] - 1);
            dp[i | j] %= TT;
        }
    }
    if (p.size() == 0) dp[(1 << p.size()) - 1] -= 1;
    cout << dp[(1 << p.size()) - 1] << endl;
    return 0;
}