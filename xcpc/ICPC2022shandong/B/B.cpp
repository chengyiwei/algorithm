#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main() {
    freopen ("B.in", "r", stdin);
    freopen ("B.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    map<int, ll> hav;
    for (int i = 1; i <= n; i++) {
        int op, x; cin >> op >> x;
        if (hav.count(op) == 0) hav[op] = 0;
        hav[op] += x;
    }
    int q; cin >> q;
    map<int, deque<pll> > c;
    vector<int> num(q + 1, 0);
    vector<vector<pll> > g (q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> num[i];
        for (int j = 1; j <= num[i]; j++) {
            int op, x; cin >> op >> x;
            c[op].push_back({x, i});
        }
        int m; cin >> m;
        g[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> g[i][j].first >> g[i][j].second;
        }
    }

    for (auto &[id, x] : c) {
        sort (x.begin(), x.end());
    }

    int ans = 0;
    queue<int> que;

    auto insert = [&] (int op, ll x) {
        if (hav.count(op) == 0) hav[op] = 0;
        hav[op] += x;
        while (c[op].size() > 0 && c[op].front().first <= hav[op]) {
            num[c[op].front().second]--;
            if (num[c[op].front().second] == 0)
                que.push(c[op].front().second);
            c[op].pop_front();
        }
        return ;
    };

    for (int i = 1; i <= q; i++)
        if (num[i] == 0) que.push(i);

    for (auto &[op, x] : hav)
        insert(op, 0);

    while (!que.empty()) {
        int x = que.front(); que.pop();
        ans++;
        for (auto &[op, x] : g[x]) {
            insert(op, x);
        }
    }
    cout << ans << '\n';
    return 0;

}