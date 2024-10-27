#include <bits/stdc++.h>

using ll = long long;
const ll INF = 1e17;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<ll> a(n + 1), g(n + 1, 0);
    std::vector<std::pair<int, ll>> p(m + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= m; i++) std::cin >> p[i].first >> p[i].second;

    sort(p.begin() + 1, p.end());

    ll sum = 0;
    for (int i = n, j = m; i ; i--) {
        while (j > 0 && p[j].first >= i) sum += p[j--].second;
        g[i] = sum;
    }
    

    std::vector<int> pre(n + 1, 0);
    pre[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (a[i] - g[i] < a[pre[i - 1]] - g[pre[i - 1]])
            pre[i] = i;
        else 
            pre[i] = pre[i - 1];
    }

    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (pos == 0 || a[i] - g[i] < a[pos] - g[pos])
            pos = i;
    }
    
    typedef std::pair<ll, int> pli;
    std::priority_queue<pli, std::vector<pli>, std::greater<pli>> pq;

    for (int i = pos + 1; i <= n; i++)
        pq.push({a[i], i});

    // std::cout << pos << ": ";
    ll ans = a[pos] - g[pos];
    std::cout << ans << " ";
    for (int k = 2; k <= n; k++) {
        ll now1 = INF, now2 = INF;
        if (!pq.empty()) {
            now1 = pq.top().first;
        }
        if (pos != 1) {
            int pos_ = pre[pos - 1];
            now2 = g[pos] + a[pos_] - g[pos_];
        }

        if (now1 < now2) {
            // std::cout << pq.top().second << ": ";
            pq.pop();
            ans += now1;
        }
        else {
            int pos_ = pre[pos - 1];
            ans += now2;
            for (int j = pos_ + 1; j < pos; j++)
                pq.push({a[j], j});
            pos = pos_;
            // std::cout << pos << ": ";
        }

    
        std::cout << ans << " ";
    }
    std::cout << "\n";
}

int main() {
    freopen ("D.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}