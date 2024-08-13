#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, q; cin >> n >> q;    
    vector<int> a(n + 1), sum(n + 1, 0), num_1(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        num_1[i] = num_1[i - 1] + (a[i] == 1);
    }
    while (q--) {
        int l, r; cin >> l >> r;
        if (l == r) {
            printf("NO\n");
            continue;
        }
        int s = sum[r] - sum[l - 1], len = r - l + 1, cnt_1 = num_1[r] - num_1[l - 1];
        if (cnt_1 * 2 + (len - cnt_1) * 1 > s) 
            printf("NO\n");
        else 
            printf("YES\n");
    }
}

signed main() {
    freopen("C.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}