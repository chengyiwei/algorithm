
#include "bits/stdc++.h"

using namespace std;
using i64 = int64_t;
constexpr int N = 1E6;

int main() {
    freopen ("D.in", "r", stdin);
    freopen ("D0.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    i64 sum = accumulate(b.begin(), b.end(), 0LL);
    i64 ans = sum;
    for (int k = 0; k <= N; k++) {
        i64 mx = 0;
        map<int, i64> mp;
        for (int i = 0; i < n && i * k <= N; i++) {
            if (a[i] >= i * k) {
                mp[a[i] - i * k] += b[i];
                mx = max(mx, mp[a[i] - i * k]);
            }
        }
        ans = min(ans, sum - mx);
    }
    cout << ans << '\n';

    return 0;
}