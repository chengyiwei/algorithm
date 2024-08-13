#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, c, d; cin >> n >> c >> d;
    vector<ll> a(n * n);
    for (int i = 0; i < n * n; i++) cin >> a[i];
    vector<vector<ll> > b(n, vector<ll>(n));
    sort (a.begin(), a.end());
    b[0][0] = a[0];
    vector<ll> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                b[i][j] = b[i][j - 1] + d;
                continue;
            }
            b[i][j] = b[i - 1][j] + c;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            p.push_back(b[i][j]);
    sort (p.begin(), p.end());
    if (p == a)
        cout << "YES\n";
    else 
        cout << "NO\n";
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}