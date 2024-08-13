#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, len; cin >> n >> k >> len;
    ll c, d; cin >> c >> d;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    auto check = [&] (ll x) {
        int num = 0;
        vector<int> pre(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            ll cz = x - a[i];
            if (cz <= 0) {num += 1; continue;}
            if (c + d * (len - 1) < cz) continue;
            if (d != 0) {
                int p;
                if (c >= cz) p = 1;
                else p = (cz - c) / d + ((cz - c) % d != 0) + 1;
                pre[max(i - len + 1, 0)] += 1, pre [max(0, i - p + 1) + 1] -= 1;
            }
            else {
                pre[max(i - len + 1, 0)] += 1, pre [max(0, i) + 1] -= 1;
            }
        }
        int max_p = 0, sum_pre = 0;
        for (int i = 0; i <= n - len + 1; i++) {
            sum_pre += pre[i];
            if (i > 0)
                max_p = max(max_p, sum_pre);
        }
        return num + max_p;
    };
    

    ll l = 0, r = 1e18 + 10;
    while (l + 1 < r) {
        ll mid = (r - l >> 1) + l;
        if (check(mid) >= k) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}