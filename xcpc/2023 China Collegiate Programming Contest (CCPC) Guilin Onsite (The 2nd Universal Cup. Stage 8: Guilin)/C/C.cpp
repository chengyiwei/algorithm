#include <bits/stdc++.h>

constexpr int TP = 30;
constexpr int TT = 998244353;
using ll = long long;

struct AS {
    std::vector<int> p;
    AS() : p(TP, 0) {}
    void insert(int x, int &cnt) {
        for (int i = TP - 1; i >= 0; i--) if (x >> i & 1) {
            if (p[i]) x ^= p[i];
            else {p[i] = x; return ;}
        }
        cnt += 1;
    }

    bool check (int x) {
        for (int i = TP - 1; i >= 0; i--) {
            if (x >> i & 1) x ^= p[i];
        }
        return x == 0;
    }
};

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n + 1, 0), f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = 2 * f[i - 1] % TT;

    for (int i = 1; i <= n; i++) std::cin >> a[i];
    int M = *std::max_element(a.begin(), a.end());
    std::vector<int> b(M + 1, 0);
    std::vector<std::vector<int>> g(M + 1);
    for (int i = 1; i <= n; i++) b[a[i]] += 1;
    for (int i = 1; i <= M; i++)
        for (int j = 0; j <= M; j += i)
            g[j].push_back(i);

    int ans = 0;
    for (int i = 0; i <= M; i++) {
        AS as;
        int now = 0;
        for (auto d : g[i]) {
            if (b[d] == 0) continue;
            now += b[d] - 1;
            as.insert(d, now);
        }
        if (as.check(i))
            ans = (ans + f[now]) % TT;
    }

    std::cout << ans - 1 << '\n';
}

int main() {
    // freopen ("C.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}