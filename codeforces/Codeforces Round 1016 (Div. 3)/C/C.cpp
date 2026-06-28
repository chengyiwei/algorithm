#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) {
        cout << (is_prime(n) ? "YES" : "NO") << '\n';
        return ;
    }
    if (n == 1) {
        int x = 0;
        for (int i = 1; i <= k; i++)
            x = x * 10 + n;
        cout << (is_prime(x) ? "YES" : "NO") << '\n';
        return ;
    }
    cout << "NO" << '\n';
    return ;
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}