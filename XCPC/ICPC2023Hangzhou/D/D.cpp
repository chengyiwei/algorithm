#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
void solve() {
    int n; cin >> n;
    if (n == 2) {
        cout << "1 -3 -3 1" << '\n';
        return ;
    }
    if (n == 3) {
        cout << "1 -10 6 6 -10 1" << '\n';
        return ;
    }
    ll a2, an;
    if (n & 1) {
        a2 = (n - 2) - 1;
        an = 1;
    }
    else { // n 为偶数
        a2 = (n - 2) * (-2);
        an = 2;
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (i & 1) printf ("1 ");
        else if (i == 2) printf ("%lld ", a2);
        else if (i == 2 * n) printf ("%lld\n", an);
        else printf ("-2 ");
    }
}
int main() {
    int t; cin >> t;
    while (t--) solve();
}