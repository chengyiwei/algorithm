#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 1e8;
int main() {
    // freopen ("C.in", "r", stdin);
    int n; cin >> n;
    ll ans = 0;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort (a.begin() + 1, a.end());
    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    int j = n;
    for (int i = 1; i <= n; i++) {
        while (j > 0 && a[i] + a[j] >= TT) j--;
        ans += sum[j] + a[i] * j;
        ans += ((sum[n] - sum[j]) + a[i] * (n - j)) - TT * (n - j);
    }
    for (int i = 1; i <= n; i++) 
        ans -= (a[i] + a[i]) % TT;
    cout << ans / 2 << endl;
    return 0;
}