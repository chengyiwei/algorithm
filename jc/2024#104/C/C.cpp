#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m; cin >> n >> m;
    int cnt = 0;
    ll n_ = n;
    while (n_ % 10 == 0) {
        n_ /= 10;
        cnt++;
    }
    int cnt_5 = 0, cnt_2 = 0;
    while (n_ % 5 == 0) {n_ /= 5, cnt_5 += 1;}
    while (n_ % 2 == 0) {n_ /= 2, cnt_2 += 1;}
    ll k = 1;
    while (true) {
        if (cnt_5 > 0) {
            if (k * 2 > m) break;
            else k *= 2, cnt_5 -= 1;
        }
        else if (cnt_2 > 0) {
            if (k * 5 > m) break;
            else k *= 5, cnt_2 -= 1;
        }
        else {
            if (k * 10 > m) break;
            else k *= 10;
        }
    }
    if (k == 1) cout << n * m << '\n';
    else {
        k *= m / k;
        cout << n * k << '\n';
    }
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}