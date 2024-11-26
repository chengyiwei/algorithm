#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    freopen ("G.out", "w", stdout);
    int n, x; cin >> n >> x;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // f[i] = f[i - 1];
        if (__gcd((i * x) ^ x, x) == 1)
            f[i] += 1;
    }
    for (int i = 1; i <= n; i++) {
       cout << i << " " << f[i] << '\n';
    }
    return 0;
}