#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

vector<ll> a, s;


int main() {
    freopen ("J.in", "r", stdin);
    int n; cin >> n;
    a.assign(n + 15, 0); s.assign(n + 15, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    if (s[n] < 0 || a[1] < 0)
        return cout << -1 << endl, 0;
    ll ans = 0,have = 0;
    int add_pos = 1, now_pos = 1;
    for (now_pos = add_pos;now_pos <= n; now_pos ++) {
        ans ++;
        have += s[now_pos];
        if (s[now_pos] >= s[add_pos])
            add_pos = now_pos;
        if (have < 0) {
            if (s[add_pos] == 0)
                return cout << -1 << endl, 0;
            ll num = -have / s[add_pos] + (-have % s[add_pos] != 0);
            have += num * s[add_pos];
            ans += num;
        }
    }

    cout << ans << endl;
    return 0;
}