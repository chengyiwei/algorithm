#include <bits/stdc++.h>
#define int __int128
using namespace std;

int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void print(int x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void solve() {
    int h, n; h = read(), n = read();
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        c[i] = read();
    
    auto check = [&](int x) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = (x - 1 + c[i]) / c[i];
            res += cnt * a[i];
        }
        return res;
    };

    int L = 0, R = 1e18;
    while (L + 1 < R) {
        int mid = (L + R) / 2;
        if (check(mid) >= h)
            R = mid;
        else
            L = mid;
    }
    print(R), putchar('\n');
}

signed main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; t = read();
    while (t--) solve();
    return 0;
}