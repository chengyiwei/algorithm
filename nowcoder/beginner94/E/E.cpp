#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("E.in", "r", stdin);
    int n, k; cin >> n >> k;
    vector<int> v(n + 1), w(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int now = 0; now <= 2000; now++) {
        int now_k = (1 << 20) - 1, now_w = (1 << 20) - 1;
        for (int i = 1; i <= n; i++) {
            if ((now & w[i]) >= now) {
                now_k &= v[i];
                now_w &= w[i];
            }
        }
        if (now_k <= k)
            ans = max(ans, now_w);
    }
    cout << ans << '\n';
    return 0;
}