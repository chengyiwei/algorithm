#include <bits/stdc++.h>

int main() {
    freopen ("M.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) {
        long long x; std::cin >> x;
        std::vector<long long> p;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                p.push_back(i);
                if (x / i != i) p.push_back(x / i);
            }
        }
        p.push_back(1); p.push_back(x);
        std::sort(p.begin(), p.end());

        long long ans = 0;
        for (int i = 1; i < p.size(); i++) {
            long long now = x / p[i - 1];
            ans += now * (p[i] - p[i - 1]);
        }
        ans += 1;
        std::cout << ans << '\n';
    }
    return 0;
}