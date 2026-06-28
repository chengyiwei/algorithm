#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b; a ^= 1, b ^= 1;
    if ((n == 1 && m == 2) || (n == 2 && m == 1)) {
        cout << "Yes" << '\n';
        return;
    }
    if ((a == 0 && b == 0) || (a == 1 && b == 0)) {
        if ((a == 1 && b == 0) && (n == 1 || m == 1)) {
            cout << "No" << '\n';
            return;
        }
        if (n % 2 == 0 && m % 2 == 0) cout << "Yes" << '\n';
        else if (n % 2 == 1 && m % 2 == 1) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }
    else if ((a == 1 && b == 1)) {
        if ((n == 1 && m == 2) || (n == 2 && m == 1)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    else if (a == 0 && b == 1) {
        if ((n == 1 && m % 2 == 0) || (m == 1 && n % 2 == 0)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}