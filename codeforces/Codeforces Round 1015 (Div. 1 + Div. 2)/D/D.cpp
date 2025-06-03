#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int p = max(n / (m + 1), k);
    // cout << p << '\n';
    for (int i = 0; i < n; i++)
        cout << i % p << ' ';
    cout << '\n';
}

int main() {
    // freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}