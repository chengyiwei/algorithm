#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lowbit(ll x) {
    return x & -x;
}

int main() {
    int T; cin >> T;
    while (T--) {
        ll x; cin >> x;
        x -= lowbit(x);
        if (x > 1) cout << x << endl;
        else cout << -1 << endl;
    }
    return 0;
}