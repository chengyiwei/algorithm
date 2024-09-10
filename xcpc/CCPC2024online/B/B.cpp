#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int TT = 998244353;
int main() {
    freopen ("B.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<ll> Fac(n + 1, 1);
    for (int i = 1; i <= n; i++) cin >> a[i], Fac[i] = Fac[i - 1] * i % TT;
    sort(a.begin() + 1, a.end());
    ll ans2 = 1;
    for (int i = 1; i <= n;) {
        int j = i;
        while (j <= n && a[j] == a[i]) j += 1;
        ans2 = ans2 * Fac[j - i];
        ans2 %= TT;
        i = j;
    }
    if (n != 1 && a[1] != a[n]) ans2 = (ans2 * 2) % TT;
    ll ans1 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans1 += a[j] - a[i];
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}