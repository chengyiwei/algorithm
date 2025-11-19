#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex = 1, n;
void AC() {
    cin >> n;
    ll ans = 0;
    vector<ll> a(n + 2, 0), b(n + 2, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i] >> b[i];
        ans += a[i];
    }
    sort (b.begin() + 1, b.begin() + n + 1, greater<ll>());
    for (int i = 1; i <= n; i ++) {
        ans -= b[i] * (i - 1);
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}