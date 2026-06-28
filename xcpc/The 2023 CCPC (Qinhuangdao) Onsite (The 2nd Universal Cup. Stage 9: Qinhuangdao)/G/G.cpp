#include <bits/stdc++.h>
#define int long long

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int ans = 0;
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    for (int i = 1; i < n; i++)
        ans += abs(a[i] - a[i - 1]);
    for (int i = 1; i < m; i++)
        ans += abs(b[i] - b[i - 1]);
    
    std::cout << ans << '\n';
    return 0;
}