#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m, a[200005], mod = 998244353;
ll p[20], fact[20], pw[200005], cnt[200005], dp[200005];

int main() {
    freopen ("F.in", "r", stdin);
    cin >> n >> m;
    int id = 0;
    ll num = m;
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            p[id] = i;
            fact[id] = 1;
            while (num % i == 0) {
                fact[id] *= i;
                num /= i;
            }
            id++;
        }
    }
    if (num != 1) {
        p[id] = num;
        fact[id++] = num;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ll val = 0;//记录a[i]对答案的贡献
        for (int j = 0; j < id; j++) {
            if (a[i] % fact[j] == 0) {
                a[i] /= fact[j];
                if (a[i] % p[j] == 0) break;
                val |= (1 << j);
            }
            while (a[i] % p[j] == 0) {
                a[i] /= p[j];
            }
        }
        if (a[i] == 1) {
            cnt[val]++;
        }
    }
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 2 % mod;
    }
    dp[0] = pw[cnt[0]];
    for (int i = 1; i < (1 << id); i++) {
        for (int j = (1 << id) - 1; j >= 0; j--) {
            dp[i | j] = (dp[i | j] + dp[j] * (pw[cnt[i]] - 1)) % mod;
        }
    }
    if (!id) dp[(1 << id) - 1]--;
    cout << dp[(1 << id) - 1] << endl;
    return 0;
}