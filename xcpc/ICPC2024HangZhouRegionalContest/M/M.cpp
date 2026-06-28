#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
    Node() : l(0), r(0) {}
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int g = 0;
    for (int i = 1; i + 1 <= n; i++) {
        g = gcd(g, abs(a[i + 1] - a[i]));
    }
    if (g == 0) {
        cout << k << " " << (long long)k * (k + 1) / 2 << "\n";
        return;
    }
    int mn = *min_element(a.begin() + 1, a.end());
    vector<int> p;
    int x = g;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            p.push_back(i);
            if (i * i != x) p.push_back(x / i);
        }
    }
    sort(p.begin(), p.end());

    auto check = [&](int d) {
        vector<int> b(n + 1, 0);
        for (int i = 1; i <= n; i++) b[i] = a[i] + d;

        vector<Node> c(n + 1);
        int root = 0;

        auto build = [&]() -> void {
            stack<int> stk; stk.push(0);
            for (int i = 1; i <= n; i++) {
                while (!stk.empty() && b[stk.top()] >= b[i]) stk.pop(); // 找到第一个小于他的
                c[i].l = c[stk.top()].r;
                c[stk.top()].r = i;
                stk.push(i);
            }
            while (stk.size() > 1) stk.pop();
            root = stk.top(); 
        };

        build();

        function<bool(int, int)> dfs = [&] (int u, int fa) -> bool {
            if (fa && b[u] % b[fa]) return false;
            int ret = 1;
            if (c[u].l) ret &= dfs(c[u].l, u);
            if (ret && c[u].r) ret &= dfs(c[u].r, u);
            return ret;
        };

        return dfs(root, 0);
    };

    int cnt = 0;
    long long sum = 0;
    for (auto x : p) {
        int d = x - mn;
        if (d < 1 || d > k) continue;
        if (check(d)) {
            cnt++;
            sum += d;
        }
    }
    cout << cnt << " " << sum << "\n";
}

int main() {
    freopen ("M.in","r",stdin);
    freopen ("M.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}