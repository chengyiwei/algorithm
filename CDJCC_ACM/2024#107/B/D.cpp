#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 998244353;

const int MAXN = 2e3 + 5;

ll dp[MAXN];

int main() {
    // freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);

    dp[1] = 1; dp[2] = 1;
    for (int i = 3; i < MAXN; i++) {
        ll res = 0;
        for (int j = 1; j < i; j++)
            res = (res + dp[j] * dp[i - j] % TT) % TT;
        dp[i] = res;
    }

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << dp[n + 1] << '\n';
    }

    return 0;    
}