#include <bits/stdc++.h>
#define int long long

constexpr int INF = 2e9;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::vector<int> x(m + 1, 0), t(m + 1, 0);
    std::vector<int> b(n + 1, 0), nxt(m + 1, 0);
    for (int i = 1; i <= m; i++) 
        std::cin >> x[i] >> t[i];

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    std::fill(b.begin(), b.end() , m + 1);
    for (int i = m; i >= 1; i--) {
        nxt[i] = b[t[i]];
        b[t[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        if (b[i] == m + 1) 
            pq.push({INF, i});
        else 
            pq.push({x[b[i]], i});
    }

    std::vector<int> now_a = a;

    int ans = 0;
    x.push_back(INF);

    for (int i = 1; i <= m + 1; i++) {
        int len = x[i] - x[i - 1];

        while (!pq.empty() && pq.top().first < x[i]) pq.pop();

        while (!pq.empty()) {
            if (len <= 0) break;
            auto [pos, id] = pq.top();
            if (now_a[id] < len) {
                pq.pop();
                len -= now_a[id];
                ans += now_a[id];
                now_a[id] = 0;
            }
            else {
                now_a[id] -= len;
                ans += len;
                len = 0;
            }
        }
        if (len > 0) break;
        now_a[t[i]] = a[t[i]];
        if (nxt[i] != m + 1)
            pq.push({nxt[i], t[i]});
        else 
            pq.push({INF, t[i]});
    }

    std::cout << ans << '\n';
}

signed main() {
    freopen ("in.in", "r", stdin);
    
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}