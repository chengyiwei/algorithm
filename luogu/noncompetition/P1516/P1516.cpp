#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
    x = y0, y = x0 - a / b * y0;
    return d;
}
int main() {
    LL n, m, x, y, L; cin >> x >> y >> m >> n >> L;
    LL a = m - n, b = L, c = y - x;
    if (a < 0) a = -a, c = -c;
    LL d = exgcd(a, b, x, y);
    if (c % d) cout << "Impossible" << endl;
    else cout << (x * (c / d) % (b / d) + (b / d)) % (b / d) << endl;
}