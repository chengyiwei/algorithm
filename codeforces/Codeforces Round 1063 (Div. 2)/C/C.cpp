#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll INF = 1e18;
ll Tex, n, a[MAXN], b[MAXN], mx1[MAXN], mx2[MAXN], mn1[MAXN], mn2[MAXN];
string s;
void AC() {
    cin >> n;
    mx1[0] = mx2[n + 1] = -INF;
    mn1[0] = mn2[n + 1] = INF;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx1[i] = max(mx1[i - 1], a[i]);
        mn1[i] = min(mn1[i - 1], a[i]);
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }
    for (int i = n; i >= 1; i --) {
        mx2[i] = max(mx2[i + 1], b[i]);
        mn2[i] = min(mn2[i + 1], b[i]);
    }
    ll L = 0, R = INF, ans = 0, LL = 0;
    map<ll, ll> mp;
    for (int i = 1; i <= n; i ++) {
        L = min(mn1[i], mn2[i]);
        R = max(mx1[i], mx2[i]);
        mp[R] = max(mp[R], L);
    }
    L = 0;
    for (int i = 1; i <= 2 * n; i ++) {
        L = max(L, mp[i]);
        // cout << L << " " << i << "\n";
        ans += L;
    }
    cout << ans << "\n";
 
}
int main() {
    freopen ("C.in", "r", stdin);
    freopen ("C.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}