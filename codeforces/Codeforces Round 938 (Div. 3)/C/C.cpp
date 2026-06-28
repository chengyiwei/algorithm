#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k; cin >> n >> k;
    deque<ll> a;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        a.push_back(x);
    }
    int now = 0; // 表示此次攻击的是头还是尾
    int p[2];
    int ans = 0;
    while (k > 0) {
        if (a.size() == 1) {
            if (a[0] <= k) 
                ans ++;
            break;
        }
        p[0] = a.front(); a.pop_front();
        p[1] = a.back(); a.pop_back();
        if (p[now] <= p[now ^ 1]) {
            k -= p[now] * 2 - 1;
            if (k < 0) break;
            ans ++;
            p[now ^ 1] -= p[now] - 1;
            now ^= 1;
            if (now == 0) a.push_front(p[now]);
            else a.push_back(p[now]);
        }
        else {
            k -= p[now ^ 1] * 2;
            if (k < 0) break;
            ans ++;
            p[now] -= p[now ^ 1];
            if (now == 0) a.push_front(p[now]);
            else a.push_back(p[now]);
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}