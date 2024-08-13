#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    ll max_x = -1, max_i = 0;

    auto check = [&](int x) {
        ll res = 0;
        for (int i = x; i <= n;  i += x)
            res += i;
        return res;
    };

    for (int i = 2; i <= n; i++) {
        if (max_x < check(i)) {
            max_x = check(i);
            max_i = i;
        }
    }
    cout << max_i << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}