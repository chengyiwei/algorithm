#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int ans = 0;
    if (n % 2 == 1) {
        n -= k;
        ans += 1;
    }
    k -= 1;
    ans += (n + k - 1) / k;
    cout << ans << '\n';
}

int main() {
    freopen ("A.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}