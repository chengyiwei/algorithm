#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("C.in", "r", stdin);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> f(n + 1, 0);
    for (int i = 2; i < n; i++)
        if (a[i - 1] >= a[i] && a[i] >= a[i + 1])
            f[i] = f[i - 1] + 1;
        else 
            f[i] = f[i - 1];
    while (q--) {
        int l, r; cin >> l >> r;
        int cnt = f[r - 1] - f[l];
        if (r - l + 1 < 3)
            cout << r - l + 1 << '\n';
        else
            cout << (r - l + 1) - cnt << '\n';
    }
    return 0;
}