#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n+1), s(n+1), t(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        cin >> s[i] >> t[i];
    for (int i = 1; i < n; i++) {
        if (a[i] >= s[i]) {
            a[i + 1] += a[i] / s[i] * t[i];
        }
    }
    cout << a[n] << '\n';
    return 0;
}