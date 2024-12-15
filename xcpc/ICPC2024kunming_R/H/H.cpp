#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double eps = 1e-8;

int dcmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    return x < y ? -1 : 1;
}

void solve() {
int n, k; cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = atan2(y, x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a.push_back(a[i]);
    }
    for (int i = 1; i < 2 * n; i++) {
        if (dcmp(a[i], a[i - 1]) == -1) a[i] += 2 * PI;
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i + k] - a[i]);
    }
    if (dcmp(ans, 0) == 0) ans = 2 * PI; 
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    freopen("H.in", "r", stdin);
    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}