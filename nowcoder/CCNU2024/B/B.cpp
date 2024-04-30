#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 1e9 + 7;
ll x, y, z;
ll read() {
    ll ret = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch <= '9' && ch >= '0') ret = ret * 10 + ch - '0', ch = getchar();
    return ret;
}

void print(ll x) {
    if (x == 0) return ;
    print(x / 10);
    putchar(x % 10 + '0');
}
int main() {
    freopen ("B.in", "r", stdin);
    freopen ("B.out","w", stdout);
    int n; cin >> n;
    ll ans = 0;
    x = read(), y = read(), z = read();
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    ll max_x = *max_element(a.begin() + 1, a.end());
    vector<ll> cnt(max_x + 1, 0), p(max_x + 1, 0);
    for (int i = 1; i <= n; i++)
        p[a[i]]++;
    for (ll d = max_x; d >= 1; d --) {
        ll now = 0, os = (x * d + y) / z;
        ll pre = 0;
        for (int j = 1; j * d <= max_x; j++) {
            pre = (pre + p[j * d] * j) % TT;
        }
        for (int j = 1; j * d <= max_x; j++) {
            now = (now + pre * p[j * d] % TT * j) % TT;
        }
        ll oa = d * d % TT;
        now = oa * now % TT;
        cnt[d] = now;
        for (int j = 2; j * d <= max_x; j++)
            cnt[d] = ((cnt[d] - cnt[j * d]) % TT + TT) % TT;
        ans = (ans + cnt[d] * os) % TT;
    }
    print(ans);
    return 0;
}