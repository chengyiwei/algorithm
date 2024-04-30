#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 998244353;
int main() {
    freopen ("F.in", "r", stdin);
    int Q, m; cin >> Q >> m;
    vector<ll> dp (m + 1, 0);
    dp[0] = 1;
    while (Q--) {
        char op; cin >> op;
        int x; cin >> x;
        if (op == '+') {
            for (int i = m; i >= x; i--)
                dp[i] = (dp[i] + dp[i - x]) % TT;
        }
        if (op == '-') {
            for (int i = x; i <= m; i++)
                dp[i] = (dp[i] - dp[i - x] + TT) % TT;
        }
        cout << dp[m] << '\n';
    }
    return 0;
}