#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int g = a[0];
    for (int i = 1; i < n; i++)
        g = __gcd(g, a[i]);
    int ans = 0;
    for (int i = 0; i < m; i++)
        ans += __gcd(g, b[i]) % g == 0;
    cout << m - ans << endl;
    return 0;
}