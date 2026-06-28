#include <bits/stdc++.h>
using namespace std;

int dp[1 << 21][21];

void update (int num, int k) {
    if (k > 20) return ;
    if (dp[num][k] > 1) return ;
    dp[num][k] += 1;
    update(num, k + 1);
    if (num >> k & 1)
        update(num ^ (1 << k), k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        int res = 0, t = 0;
        for (int j = 20; j >= 0; j--) {
            if (a[i] >> j & 1) 
                res |= 1 << j;
            else if (dp[t | 1 << j][20] > 1) {
                res |= 1 << j;
                t |= 1 << j;
            }
        }
        update(a[i], 0);
        if (i <= n - 2)
            ans = max(ans, res);
    }
    cout << ans << '\n';
    return 0;
}