#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p[5][3];

int main() {
    freopen ("D.in", "r", stdin);
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    
    p[4][2] = 8, p[4][1] = 4, p[1][2] = 3, p[1][1] = 2, p[2][2] = 6, p[2][1] = 3, p[3][2] = 7, p[3][1] = 3;

    if (x1 < 0) {
        int num = (-x1 / 4) + (-x1 % 4 != 0); 
        x1 += 4 * num;
        x2 += 4 * num;
    }
    if (y1 < 0) {
        int num = (-y1 / 2) + (-y1 % 2 != 0);
        y1 += 2 * num;
        y2 += 2 * num;
    }
    auto calc = [&] (ll x, ll y) {
        ll num_x = x / 4, dx = x - 4 * num_x;
        ll num_y = y / 2, dy = y - 2 * num_y;
        ll ret = num_x * num_y * p[4][2];
        ret += num_x * p[4][dy];
        ret += num_y * p[dx][2];
        ret += p[dx][dy];
        return ret;
    };
    // cout << calc(x2, y2) << " " << calc(x1, y2) << " " << calc(x2, y1) << " " << calc(x1, y1) << endl;
    ll ans = calc(x2, y2) - calc(x1, y2) - calc(x2, y1) + calc(x1, y1);
    cout << ans << endl;
    return 0;
}