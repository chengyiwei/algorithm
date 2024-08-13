#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; cin >> n;
    vector<ll> p(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> p[i], p[i] %= 3, sum += p[i];
    sum %= 3;
    if (sum == 0) {
        cout << 0 << endl;
        return;
    }
    else if (sum == 2) {
        cout << 1 << endl;
        return;
    }
    else {
        for (int i = 1; i <= n; i++)
            if (p[i] == 1) {
                cout << 1 << endl;
                return;
            }
        cout << 2 << endl;
        return;
    }
}

int main() {
    // freopen ("B.in", "r", stdin); // Change B to the problem's letter (A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P
    int t; cin >> t;
    while (t--) solve();
}