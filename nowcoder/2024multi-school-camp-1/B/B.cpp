#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e3 + 5;

ll n, m, TT, C[MAXN][MAXN], dp[MAXN][MAXN], pw[MAXN];

ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1; 
    }
    return res;
}

void init() {
    C[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % TT;
    }

    dp[0][0] = 1;
    for (int i = 1; i < MAXN; i++) 
        for (int j = 1; j < MAXN; j++)
            dp[i][j] = i * (dp[i - 1][j - 1] + dp[i][j - 1]) % TT;

    pw[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pw[i] = pw[i - 1] * 2 % TT;
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> TT;
    init();
    ll ans = 0;
    for (int k = 2; k <= n; k++) {
        ll cur1 = 1, cur2 = 1;
        for (int t = 1; t <= m - 1; t++)
            cur1 = cur1 * pw[n - k] % TT, cur2 = cur2 * (pw[k] - 1 + TT) % TT;
        ll cur3 = 0, cur4 = 1;
        for (int t = m - 1; t >= k; t--) {
            cur3 = (cur3 + C[m - 1][t] * dp[k][t] % TT * cur4 % TT) % TT;
            cur4 = cur4 * (pw[k] - 1 - k + TT) % TT;
        }
        ll now = cur1 * (cur2 - cur3 + TT) % TT * C[n][k] % TT;
        ans = (ans + now) % TT;
    }
    cout << ans << endl;
    return 0;
}