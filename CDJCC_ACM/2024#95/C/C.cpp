#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int n = a + b + c;
    if (c != a + 1) {cout << -1 << '\n'; return ;}
    vector<int> dep(n + 1, 0);
    for (int i = 2; i <= a + c; i++)
        dep[i] = dep[i >> 1] + 1;
    int fa = a + c + 1 >> 1;
    for (int i = a + c + 1; i <= n; i++) {
        dep[i] = dep[fa] + 1;
        fa += 1;
    }
    cout << dep[n] << '\n';
}

int main() {
    // freopen ("C.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}