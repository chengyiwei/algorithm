#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
    int up = 1, dn = 1;
    int n; cin >> n;
    vector<int> op(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> op[i];
    int cnt_0 = 0;
    for (int i = 1; i <= n; i++) {
        if (op[i] == 1) 
            up += 1, dn += 1;
        if (op[i] == -1)
            dn -= 1;
        if (op[i] == 0)
            cnt_0 += 1, dn -= 1;
        if (dn < 1) {
            if (cnt_0 > 0) {
                cnt_0 -= 1;
                dn += 2;
                up += 1;
            }
            else {
                cout << -1 << '\n';
                return ;
            }
        }
    }
    auto g = __gcd(up, dn);
    up /= g, dn /= g;
    cout << up << " " << dn << '\n';
    return ;
}

int main() {
    // freopen ("G.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}