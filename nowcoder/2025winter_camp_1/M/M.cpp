#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int min_1, min_2, max_1, max_2;
    int ans = (a[n - 1] - a[0]) * 2;
    for (int i = 0; i < n - 1; i++) {
        min_1 = a[0] * 2;
        max_1 = a[i] * 2;

        min_2 = a[i + 1];
        max_2 = a[n - 1];
        
        ans = min(ans, max(max_1, max_2) - min(min_1, min_2));
    }
    cout << ans << '\n';
    return 0;
}