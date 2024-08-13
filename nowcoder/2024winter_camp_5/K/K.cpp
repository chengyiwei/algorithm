#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    int n, p; cin >> n >> p;
    vector<int> f(n + 1, INF); f[0] = 0;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        b = min(b, n - 1);
        for (int j = b; j <= n - 1; j ++)
            f[j] = min(f[j], f[j - b] + a);
    }
    int ans = INF;
    for (int i = n - 1; i >= 0; i--) {
        f[i] = min(f[i], f[i + 1]);
        ans = min(ans, f[i] + p * (n - i));
    }
    cout << ans << endl;
    return 0;
}