#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 998244353;
ll ans = 0;
int main() {
    // freopen ("D.in", "r", stdin);
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> sum(n + 1, 0);
    vector<ll> pow10(15, 1);
    for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + a[i]) % TT;
    for (int i = 1; i <= 14; i++) pow10[i] = pow10[i - 1] * 10 % TT;
    for (int j = 2; j <= n; j++) {
        ans += a[j] * (j - 1);
        int num = log10(a[j]) + 1;
        ans += sum[j - 1] * pow10[num] % TT;
        ans %= TT;
    }
    cout << ans % TT << endl;
    return 0;
}