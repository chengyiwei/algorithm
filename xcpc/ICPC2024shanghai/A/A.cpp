#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int calc(int x_up, int y_up, int up) {
    int res = 0;
    for (int i = 1; i <= x_up; i++) {
        res += max(0, min(up - i, y_up));
    }
    return res;
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            int now = 0;
            int a = min(i, j), b = min(i, m - j), d = min(n - i, j), c = min(n - i, m - j);
            now += a + b + c + d;
            now += calc(j, m - j, n - i) + calc(n - i, i, m - j) + calc(m - j, j, i) + calc(i, n - i, j);
            cout << now << "\n "[j != m];
        }
    return 0;
}