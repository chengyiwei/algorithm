#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll even = 0, odd = 0;
    ll num_even = 0, num_odd = 0;
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if (x & 1) {
            odd += x;
            num_odd++;
        }else {
            even += x;
            num_even++;
        }
    }
    while (q--) {
        int op; ll x; cin >> op >> x;
        if (op & 1) {
            if (x & 1) {
                odd += x * num_odd;
                even += odd;
                num_even += num_odd;
                odd = 0; num_odd = 0;
            }
            else {
                odd += x * num_odd;
            }
        }else {
            if (x & 1) {
                even += x * num_even;
                odd += even;
                num_odd += num_even;
                even = 0; num_even = 0;
            }
            else {
                even += x * num_even;
            }
        }
        cout << even + odd << '\n';
    }
}

int main() {
    freopen ("B.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
}