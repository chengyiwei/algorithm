#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int p = 7;

int n, m, l, r, dp[maxn], lst[30], ans;
string s, t;

void f1 () {
    for (int i = l + 1; i < r; i++) {
        if (lst[s[i]]) dp[i] = (dp[i - 1] * 2 - dp[lst[s[i]] - 1]) % MOD;
        else dp[i] = (dp[i - 1] * 2 + 1) % MOD;
        lst[s[i]] = i;
    }
    ans = (ans + dp[r - 1] + 1) % MOD;
}

void f2 (int x) {
    int tx, ty, k;
    tx = ty = 0; k = 1;
    for (int i = 0; i < m; i++) {
        tx = (tx * p + t[m - i - 1]) % MOD;
        ty = (t[m - i - 1] * k + ty) % MOD;
        k = k * p % MOD;
        if (tx == ty && i >= x - 1) ans += 1;
    }
}

signed main() {
    cin >> n >> m >> s >> t;
    int num = 0;
    for (l = 0; l < n; l++) {
        if (s[l] == t[num]) num += 1;
        if (num == m) break;
    }
    if (num < m) {
        cout << 0 << endl;
        return 0;
    }
    num = 0;
    for (r = n - 1; r > l; r--) {
        if (s[r] == t[num]) num += 1;
        if (num == m) break;
    }
    if (l < r) f1();
    f2(m - num);
    cout << (ans + MOD) % MOD << endl;
    return 0;
}