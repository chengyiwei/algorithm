#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

struct query {
    int l, r, mex;
    bool operator < (const query &rhs) const {
        return r < rhs.r;
    }
};

void solve() {
    int n, M; std::cin >> n >> M;
    std::vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; i++) std::cin >> a[i];

    M = *max_element(a.begin() + 1, a.end()) + 1;
    std::vector<std::vector<int>> p(M + 1);
    for (int i = 1; i <= M; i++)
        p[i].push_back(0);
    for (int i = 1; i <= n; i++)
        p[a[i]].push_back(i);
    for (int i = 1; i <= M; i++)
        p[i].push_back(n + 1);

    std::vector<query> q;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j + 1 < p[i].size(); j++) {
            if (p[i][j + 1] - p[i][j] <= 1) continue;
            q.push_back({p[i][j] + 1, p[i][j + 1] - 1, i});
        }
    }

    std::vector<int> c(n + 2, 0), pre(M + 1, 0);

    auto add_x  = [&] (int x, int val) -> void {
        for (; x <= n; x += x & -x)
            c[x] += val;
    };

    auto query_x = [&] (int x) -> int {
        int res = 0;
        for (; x; x -= x & -x)
            res += c[x];
        return res;
    };

    std::sort(q.begin(), q.end());

    int j = 0, ans = -INF;
    for (int i = 1; i <= n; i++) {
        if (pre[a[i]]) add_x(pre[a[i]], -1);
        add_x(i, 1);
        pre[a[i]] = i;
        while (j < q.size() && q[j].r == i) {
            int now = query_x(q[j].r) - query_x(q[j].l - 1);
            ans = std::max(ans, now - q[j].mex);
            j += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    freopen ("I.in", "r", stdin);
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(NULL); std::cout.tie(NULL);

    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}