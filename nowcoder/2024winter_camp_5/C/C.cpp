#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int n;
LL ans, a[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] -= 1;
    ans = a[1]; a[1] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i + 1]) ans += a[i], a[i + 1] -= a[i];
        else ans += a[i + 1], a[i + 1] = 0;
    }
    ans += a[n];
    cout << ans << endl;
    return 0;
}