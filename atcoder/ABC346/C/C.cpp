#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int ans = k * (k + 1) / 2;
    for (int &x : a) {
        if (x <= k)
            ans -= x;
    }
    cout << ans << endl;
    return 0;
}