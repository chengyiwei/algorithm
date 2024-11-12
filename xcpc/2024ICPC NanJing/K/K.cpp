#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;

void solve() {
    int n, m, k, w; std::cin >> n >> m >> k >> w;
    std::vector<int> a(n), b(m);
    std::vector<int> p;
    p.push_back(k);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] - k + 1 >= 1) p.push_back(a[i]);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
        if (b[i] + k <= w) p.push_back(b[i] + k);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::sort(p.begin(), p.end());
    p.erase(std::unique(p.begin(),p.end()), p.end());

    auto sum_b = [&] (int L, int R) -> bool {
        auto it_L = std::lower_bound(b.begin(), b.end(), L);
        auto it_R = std::upper_bound(b.begin(), b.end(), R);
        return it_L != it_R;
    };

    std::map<int, int> dp;
    std::map<int, int> ans_pre;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    int ans = INF, ans_i = 0;

    for (auto i : p) {
        if (sum_b(i - k + 1, i) == true) continue;
        int ql = k, qr = i - k;
        auto pre_it = std::lower_bound(a.begin(), a.end(), i - k + 1);
        if (pre_it == a.begin()) { // 前面没有红色
            dp[i] = 1;
        }
        else {
            int pre_pos = *(--pre_it);
            ql = std::max(ql, pre_pos), qr = std::min(qr, pre_pos + k - 1);
            if (ql > qr) continue;

            while (!dp.empty() && dp.begin()->first <= qr)
                pq.push({dp.begin()->second, dp.begin()->first}), dp.erase(dp.begin());

            while (!pq.empty() && pq.top().second < ql)
                pq.pop();
            
            if (pq.empty()) {std::cout << -1 << '\n'; return ;}

            dp[i] = pq.top().first + 1;
            ans_pre[i] = pq.top().second;
        }
        // std::cout << i << " " << dp[i] << "\n";
        if (std::upper_bound(a.begin(), a.end(), i) - a.begin() == n && ans > dp[i])
            ans = dp[i], ans_i = i;
    }

    if (ans == INF) {
        std::cout << -1 << '\n';
        return ;
    }

    std::vector<int> ans_ans;

    for (int i = ans_i;;) {
        ans_ans.push_back(i - k + 1);
        if (ans_pre.find(i) == ans_pre.end())
            break;
        i = ans_pre[i];
    }
    std::sort(ans_ans.begin(), ans_ans.end());

    // assert(ans_ans.size() == ans);
    // if(ans_ans.size() != ans) {
    //     std::cout << -1 << "\n";
    //     return ;
    // }

    std::cout << ans << '\n';
    // for (auto x : ans_ans)
    //     std::cout << x << " ";
    // std::cout << "\n";
}

int main() {
    freopen ("K.in", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}