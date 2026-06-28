#include <bits/stdc++.h>
// #pragma GCC optimize(2)
using namespace std;
#define double long double
const double eps = 1e-7;
const double INF = 1e9;

const int MAXN = 1e5 + 10;
int n, k;
pair<double, double> p[MAXN];
double a[MAXN];
double c[MAXN];

int check(double mid) {
    for (int i = 1; i <= n; i++)  {
        auto [x, y] = p[i];
        a[i] = y - mid * x;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt == 0 || c[cnt] <= a[i]) c[++cnt] = a[i];
        else {
            int pos = lower_bound(c + 1, c + 1 + cnt, a[i]) - c ;
            c[pos] = a[i];
        }
    }
    
    return cnt >= k;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        auto &[x, y] = p[i];
        cin >> x >> y;
    }
    double L = -INF, R = INF;
    while (fabs(R - L) >= eps) {
        double mid = (L + R) / 2;
        if (check(mid)) L = mid;
        else R = mid;
    }
    printf("%.6Lf\n", R);
    return 0;
}