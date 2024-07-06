#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> get_factors (ll x) {
    vector<ll> res;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x) res.push_back(x / i);
        }
    }
    if (x > 1) res.push_back(x);
    res.push_back(1);
    return res;
}

int main() {
    freopen ("B.in", "r", stdin);
    int t; cin >> t;
    while (t--) {
        ll x, n; cin >> x >> n;
        vector<ll> factors = get_factors(x);
        sort(factors.begin(), factors.end());
        for (int i = factors.size() - 1; i >= 0; i--) {
            ll p = factors[i];
            if (p * n <= x) {
                cout << p << endl;
                break;
            }
        }
    }
    return 0;
}