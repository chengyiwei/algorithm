#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve() {
    LL a, b, c; cin >> a >> b >> c;
    LL ans = a;
    ans += b / 3;
    b %= 3;
    if (b > 0 && 3 - b > c) ans = -1;
    else {
        if (b > 0) {
            ans += 1;  
            c -= 3 - b;
        }
        ans += c / 3 + (c % 3 != 0);
    }
    cout << ans << '\n';
}

int main() {
    freopen ("A.in","r",stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}