#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    int x = n - k - 1;
    if (x * m < n)
        puts("NO");
    else
        puts("YES");
}

int main() {
    // freopen ("D.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}