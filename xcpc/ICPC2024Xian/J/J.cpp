#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
typedef long long ll;
int cmp (double x, double y) {
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

int main() {
    freopen("J.in", "r", stdin);
    int a, b; cin >> a >> b;
    if (a < b) swap(a, b);
    ll ans = 0;
    for (int i = 0; i + 1 <= a; i++) {
        double left = 1.0 * i * b / a, right = 1.0 * (i + 1) * b / a;
        int now = left + eps;
        left -= now; right -= now;
        if (cmp(left + right, 1.0) >= 0)
            now++;
        ans += now;
    }
    cout << ans << endl;
    return 0;
}