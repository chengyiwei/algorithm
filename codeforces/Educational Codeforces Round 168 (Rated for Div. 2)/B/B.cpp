#include <bits/stdc++.h>
using namespace std;

int calc(vector<int> a, vector<int> b, int n) {
    int res = 0;
    for (int i = 2; i + 1 <= n; i++) {
        if (a[i] == 0 && a[i - 1] == 0 && a[i + 1] == 0)
        if (b[i] == 0 && b[i - 1] == 1 && b[i + 1] == 1)
            res += 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 2, 0), b(n + 2, 0);
    a[0] = a[n + 1] = b[0] = b[n + 1] = 1;
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        if (x == 'x') a[i] = 1;
        else a[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        if (x == 'x') b[i] = 1;
        else b[i] = 0;
    }
    int ans = calc(a, b, n) + calc(b, a, n);
    cout << ans << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}