#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double eps = 1e-8;

int dcmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    return x < y ? -1 : 1;
}

double calc(double x, double y) {
    if (x == 0) {
        if (y > 0) return PI / 2;
        else return 3 * PI / 2;
    }
    if (x >= 0) {
        if (y >= 0) return atan(y / x);
        else return 2 * PI + atan(y / x);
    }
    else {
        if (y >= 0) return PI + atan(y / x);
        else return PI + atan(y / x);
    }
}

struct Node {
    int cnt;
    double angle;
};

void solve() {
    int n, k; cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = atan2(y, x);
    }
    sort(a.begin(), a.end());
    for (auto x : a) printf("%.2f ", x); puts("");
    vector<Node> b;
    for (int i = 0; i < n;) {
        int j = i;
        Node tmp; tmp.cnt = 0, tmp.angle = a[i];
        while (j < n && dcmp(a[j], a[i]) == 0) {
            tmp.cnt++;
            j++;
        }
        b.push_back(tmp);
        i = j;
    }

    int tot = 0;
    double ans = 0;
    for (int i = 0, k = 0; i < b.size(); i++) {
        while (tot <= k) {
            tot += b[k].cnt;
            k = (k + 1) % b.size();
        }
        double now = b[k].angle - b[i].angle;
        if (now > 2 * PI) now -= 2 * PI;
        if (now < 0) now += 2 * PI;
        if (now < eps) now += 2 * PI;
        ans = max(ans, now);
        tot -= b[i].cnt;
    }
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    freopen("H.in", "r", stdin);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}