#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n, m; cin >> n >> m;
    vector<int> t(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        cin >> t[i];
    sort (t.begin() + 1, t.end());
    
    int max_t = t.back() + m;
    vector<int> g(max_t + 1, 0), s(max_t + 1, 0), dp (max_t + 1, INF);
    for (int i = 1; i <= n; i++) 
        g[t[i]] += 1, s[t[i]] += t[i];
    for (int i = 1; i <= max_t; i++) 
        g[i] += g[i - 1], s[i] += s[i - 1];
    
    auto x = [&](int j) {return g[j];};
    auto y = [&](int j) {return dp[j] + s[j];};
    auto slope = [&](int i, int j) {
        if (x(i) == x(j)) return y(j) > y(i) ? 1.0 * INF : -1.0 * INF;
        return 1.0 * (y(i) - y(j)) / (x(i) - x(j));
    };

    for (int i = 0; i < m; i++)
        dp[i] = g[i] * i - s[i];
    
    deque <int> q; q.push_back(0);
    for (int i = m; i <= max_t; i++) {
        while (q.size() >= 2 && slope(q[q.size() - 2], q[q.size() - 1]) >= slope(q[q.size() - 1], i - m))
            q.pop_back();
        q.push_back(i - m);

        while (q.size() >= 2 && slope(q[0], q[1]) <= i)
            q.pop_front();
        
        int j = q.front();
        dp[i] = dp[j] + (g[i] - g[j]) * i - (s[i] - s[j]);
    }

    int ans = INF;
    for (int i = t.back(); i <= max_t; i++) 
        ans = min(ans, dp[i]);
    cout << ans << '\n';
    return 0;

}