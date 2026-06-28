#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int min_i = min_element(a.begin() + 1, a.end()) - a.begin();
    ll g = 0;
    for (int i = 1; i <= n; i++) {
        if (i == min_i) continue;
        if (a[i] % a[min_i] == 0) {
            g = gcd(g, a[i]);
        }
    }
    cout << (g == a[min_i] ? "Yes" : "No") << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}