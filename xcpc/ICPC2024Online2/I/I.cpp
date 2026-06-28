#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll x ; cin >> x;
    ll b[35] = {0}; b[32] = 1;
    for (ll i = 0; i < 32; i++) {
        b[i] = x >> i & 1;
    }
    int st = 0;
    while (b[st] == 0) st ++ ;
    if (st > 1) {cout << "NO" << '\n'; return ;}
    cout << "YES" << '\n';
    for (int i = st; i < 32;) {
        int j = i + 1;
        while (b[j] == 0) j += 1;
        for (int k = i; k < j - 1; k++)
            b[k] = -1;
        b[j - 1] = 1;
        i = j;
    }
    for (int i = 0; i < 32; i++) {
        cout << b[i];
        if ((i + 1) % 8 == 0) cout << '\n';
        else cout << " ";
    }
}

int main() {
    // freopen ("I.in", "r", stdin);
    // ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}