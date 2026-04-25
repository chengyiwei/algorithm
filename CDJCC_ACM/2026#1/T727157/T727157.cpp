#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int n, m; cin >> n >> m;
    int g = 360;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        g = gcd(g, gcd(x, 360 - x));
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        cout << (x % g == 0 ? "YES" : "NO") << '\n';
    }
    return 0;
}