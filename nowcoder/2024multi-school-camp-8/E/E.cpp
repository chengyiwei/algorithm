#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn = 1e6 + 5;
constexpr int M = 108;

vector<int> prime;

int s(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

vector<int> get_prime() {
    vector<int> prime;
    vector<int> vis(maxn, 0);
    for (int i = 2; i < maxn; i++) {
        if (vis[i] == 0) {
            prime.push_back(i);
            for (int j = i + i; j < maxn; j += i)
                vis[j] = 1;
        }
    }
    return prime;
}

void solve() {
    int n; cin >> n;
    const int L = max(n - M, 1ll), R = n, len = R - L + 1;
    vector<int> a(len);
    vector<vector<pair<int, int>>> p(len, vector<pair<int, int>>(0));
    for (int i = L; i <= R; i++) a[i - L] = i;
    for (auto v : prime) {
        int pos = (L + v - 1) / v * v - L; 
        if (pos >= len) continue;
        for (int i = pos; i < len; i += v) {
            int cnt = 0;
            while (a[i] % v == 0) {
                a[i] /= v; cnt += 1;
            }
            if (cnt) p[i].push_back({v, cnt});
        }
    }
    for (int i = 0; i < len; i++) {
        if (a[i] > 1) p[i].push_back({a[i], 1});
    }
    
    set<int> ans;
    
    auto dfs = [&] (auto &&dfs, int pos, int now, vector<pair<int, int>> &p) -> void {
        auto [pr, cnt] = p[pos];
        if (pos == (int)p.size()) {
            int Sm = s(now);
            if (n % now == Sm) ans.insert(now);
            return;
        }
        for (int i = 0; i <= cnt; i++) {
            dfs(dfs, pos + 1, now, p);
            now *= pr;
        }
    };

    for (int i = 0; i < len; i++) {
        if (p[i].empty()) continue;
        dfs(dfs, 0, 1, p[i]);
    }

    cout << ans.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    prime = get_prime();
    while (T--) solve();
    return 0;
}