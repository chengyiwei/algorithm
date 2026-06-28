#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<int> ord(n);
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return b[i] * (a[j] - 1) > b[j] * (a[i] - 1);
    });
    vector<ll> dp(k + 1, -INF);
    dp[0] = 1;
    for (auto i : ord) {
        auto ndp = dp;
        for (int j = 0; j < k; j++) {
            if (dp[j] != -INF) {
                ndp[j + 1] = max(ndp[j + 1], dp[j] * a[i] + b[i]);
            }
        }
        dp = ndp;
    }
    cout << dp[k] << endl;
    return 0;
}