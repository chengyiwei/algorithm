#include <bits/stdc++.h>

using ll = long long;

int main() {
    freopen ("temp.in", "r", stdin);
    int n;
    while (std::cin >> n) {
        if (n == 0) break;
        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) std::cin >> a[i];

        if (*std::max_element(a.begin() + 1, a.end()) < 0) {
            std::cout << 0 << " " << a[1] << " " << a[n] << '\n';
            continue;
        }

        std::vector<ll> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];

        int min_i = 0, ans_i, ans_j;
        int max_ = -1;
        for (int i = 1; i <= n; i++) {
            if (sum[i] - sum[min_i] > max_) {
                max_ = sum[i] - sum[min_i];
                ans_i = min_i;
                ans_j = i;
            }
            if (sum[i] < sum[min_i]) min_i = i;
        }
        std::cout << max_ << " " << a[ans_i + 1] << " " << a[ans_j] << '\n';
    }
    return 0;
}