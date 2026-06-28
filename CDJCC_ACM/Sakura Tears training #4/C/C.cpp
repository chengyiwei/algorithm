#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> ans(n + 1);
    vector<ll> b(n + 1);

    for (int i = 1; i <= n; i++) b[i] = a[i] - i;

    map<int, int> mp;
    priority_queue<pair<int, int>> pq;
    
    auto in = [&] (int x) {
        if (mp.find(x) == mp.end()) mp[x] = 1;
        else mp[x]++;
        pq.push({mp[x], x});
    };

    auto del = [&] (int x) {
        if (mp.find(x) == mp.end()) return ;
        if (mp[x] == 1) mp.erase(x);
        else mp[x]--, pq.push({mp[x], x});
    };


    auto get_max = [&] () -> int {
        while (mp[pq.top().second] != pq.top().first) pq.pop();
        return pq.top().first;
    };
    
    for (int i = 1; i <= k; i++) in(b[i]);
    ans[1] = k - get_max();

    for (int i = 2; i + k - 1 <= n; i++) {
        del(b[i - 1]);
        in(b[i + k - 1]);
        ans[i] = k - get_max();
    }

    while (q--) {
        int l, r; cin >> l >> r;
        cout << ans[l] << '\n';
    }
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}