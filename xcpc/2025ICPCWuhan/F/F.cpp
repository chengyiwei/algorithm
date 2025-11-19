#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 5;
ll Tex, n, q;
pair<ll, ll> a[MAXN];
void AC() {
    cin >> n >> q;
    for (int i = 1; i <= q; i ++) {
        cin >> a[i].first >> a[i].second;
    }
    sort (a + 1, a + q + 1);
    ll tmp = 0, mx = 0;
    for (int i = 1; i <= q; i ++) {
        if (a[i].first > mx) {
            mx = a[i].second;
            tmp ++;
        }
        else mx = min(a[i].second, mx);
    }
    for (int i = 1; i <= 30; i ++) {
        if ((tmp >> i) == 0) {
            cout << i << "\n";
            return;
        }
    }
}
int main() {
    // freopen("out.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}