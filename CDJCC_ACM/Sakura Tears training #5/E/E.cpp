#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n > 60) {
        cout << "1\n";
        return 0;
    }
    vector<int> a(n + 1), sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                if ((sum[i - 1] ^ sum[j - 1]) > (sum[j - 1] ^ sum[k])) {
                    ans = min(ans, k - i - 1);
                }
            }
        }
    }
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
}