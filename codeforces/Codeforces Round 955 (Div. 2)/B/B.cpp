#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    map<int, int> mp;
    while (k > 0) {
        if(1) {
            int d = y - x % y;
            if (k >= d) {
                x += d;
                while (x % y == 0)
                    x /= y;
                k -= d;
            }
            else {
                x += k;
                k = 0;
            }
        }
        if (k == 0) break;
        if (mp.count(x))
            k %= (k - mp[x]);
        else
            mp[x] = k;
    }
    cout << x << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}