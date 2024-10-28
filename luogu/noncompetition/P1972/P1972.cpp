#include <bits/stdc++.h>

struct query {
    int l, r, id;
    bool operator < (const query &A) const {
        return r < A.r;
    }
};

int main() {
    freopen ("P1972.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n; std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    int m; std::cin >> m;
    std::vector<query> ask(m);
    for (int i = 0; i < m; i++)
        std::cin >> ask[i].l >> ask[i].r, ask[i].id = i;

    int M = *std::max_element(a.begin() + 1, a.end());
    std::vector<int> c(n + 1, 0);
    
    auto add_x = [&] (int x, int val) {
        for (int i = x; i <= n; i += i & -i)
            c[i] += val;
    };

    sort(ask.begin(), ask.end());

    auto query_x = [&] (int x) {
        int ret = 0;
        for (int i = x; i; i -= i & -i)
            ret += c[i];
        return ret;
    };
    
    int pos = 0;
    std::vector<int> b(M + 1, 0), ans(m, 0);
    for (int i = 1; i <= n; i++) {
        if (b[a[i]] != 0) add_x(b[a[i]], -1);
        b[a[i]] = i;
        add_x(i, 1);
        while (pos < m && ask[pos].r == i) {
            ans[ask[pos].id] = query_x(i) - query_x(ask[pos].l - 1);
            pos += 1;
        }
    }

    for (int i = 0; i < m; i++)
        std::cout << ans[i] << '\n';
    
    return 0;
}