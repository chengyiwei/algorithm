#include <bits/stdc++.h>

constexpr int N = 20, INF = 0x3f3f3f3f;

std::pair<int, int> merge(std::pair<int, int> a, std::pair<int, int> b) {
    std::vector<int> v = {a.first, a.second, b.first, b.second};
    std::sort(v.rbegin(), v.rend());
    return {v[0], v[1]};
}

int main() {
    freopen ("E.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int n; std::cin >> n;
    std::vector<std::pair<int, int>> a(1 << n);

    for (int i = 0; i < (1 << n); i++) {
        int x; std::cin >> x;
        a[i] = {x, -INF};
    }

    for (int i = 0; i < n; i++) 
        for (int mask = 0; mask < (1 << n); mask++) 
            if ((mask & (1 << i))) 
                a[mask] = merge(a[mask], a[mask ^ (1 << i)]);
    
    int ans = -INF;
    for (int mask = 1; mask < (1 << n); mask++) {
        ans = std::max(ans, a[mask].first + a[mask].second);
        std::cout << ans << '\n';
    }
    
    return 0;
}