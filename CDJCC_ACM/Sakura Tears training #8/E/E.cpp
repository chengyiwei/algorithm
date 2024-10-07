#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int c[MAXN];
void update (int x, int val) {
    for (; x < MAXN; x += x & -x) c[x] = max(c[x], val);
}

int get (int x) {
    int ans = -INF;
    for (; x; x -= x & -x) ans = max(ans, c[x]);
    return ans;
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    memset(c, -INF, sizeof(c));
    vector<int> a(n + 1, 0), dp(n + 1, 0);
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    auto tmp = sum;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i <= n; i++) {
        sum[i] = lower_bound(tmp.begin(), tmp.end(), sum[i]) - tmp.begin() + 1;
    }
    update(sum[0], 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i - 1], get(sum[i]) + i);
        update(sum[i], dp[i] - i);
    }
    cout << dp[n] << '\n';
    return 0;
}