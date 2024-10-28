#include <bits/stdc++.h>

void solve() {
    int n, M; std::cin >> n >> M;
    std::vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; i++) std::cin >> a[i];

    M = *max_element(a.begin() + 1, a.end()) + 1;
    std::vector<std::vector<int>> p(M + 1);
    for (int i = 1; i <= n; i++)
        p[a[i]].push_back(i);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}