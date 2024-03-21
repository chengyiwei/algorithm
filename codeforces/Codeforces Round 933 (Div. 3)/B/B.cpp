#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 2; i++) {
        if (a[i] > a[i + 1]) {
            puts("NO"); return ;
        }
        int x = a[i];
        if (a[i + 1] < x * 2) {
            puts("NO"); return ;
        }
        if (a[i + 2] < x) {
            puts("NO"); return ;
        }
        a[i] -= x; a[i + 1] -= x * 2; a[i + 2] -= x;
    }
    if (a[n - 1] != 0 || a[n] != 0) {
        puts("NO"); return ;
    }
    puts("YES");
}

int main() {
    freopen ("B.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
}