#include <bits/stdc++.h>

void solve() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    s = " " + s;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '1') cnt += 1;
    
    long long ans = 0;
    std::deque<int> dq;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '1')
            dq.push_back(i);
        else {
            if (dq.empty()) continue;
            int j = dq.front(); dq.pop_front();
            ans -= j;
        }
    }
    while (dq.size() > 1) {
        int j = dq.front(); dq.pop_front();
        int i = dq.back(); dq.pop_back();
        ans -= j;
    }
    std::cout << ans + 1ll * n * (n + 1) / 2 << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    int T; std::cin >> T;
    while (T--) solve();
}