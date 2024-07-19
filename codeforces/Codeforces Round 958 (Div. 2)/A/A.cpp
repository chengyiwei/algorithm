#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int cnt = 0;
    while (n > 1) {
        n -= k - 1;
        cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}