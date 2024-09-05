#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l = 1, r = 999;
    while (r - l > 2) {
        int a = (2 * l + r) / 3;
        int b = (2 * r + l) / 3;
        cout << "? " << a << " " << b << endl;

        int res; cin >> res;

        if (res == (a + 1) * (b + 1)) r = a;
        else if (res == a * b) l = b;
        else l = a, r = b;
    }
    int ans = r;
    if (r - l == 2) {
        cout << "? " << 1 << " " << l + 1 << endl;
        int res; cin >> res;
        if (res == l + 1) ans = r;
        else ans = l + 1;
    }
    cout << "! " << ans << endl;
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}