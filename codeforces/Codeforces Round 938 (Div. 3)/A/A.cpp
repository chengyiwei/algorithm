#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    b = min(b, a * 2);
    int ans = n / 2 * b + (n % 2) * a;
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}