#include <bits/stdc++.h>
using namespace std;

const int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
const int TT = 1e9 + 7;
using ll = long long;
using pil = pair<int, ll>;

int main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int max_x = *max_element(a.begin() + 1, a.end());
    vector<vector<pil>> p(max_x + 1);

    for (int i = 1; i <= n; i++) {
        int _ = 0; ll val = 1;
        for (int j = 0; j < 11; j++) {
            while (a[i] % prime[j] == 0) {
                a[i] /= prime[j];
                if (_ >> j & 1) val = (val * prime[j]) % TT;
                _ ^= 1 << j;
            }
        }
        p[a[i]].emplace_back(_, val);
    }

    vector<ll> cur(1 << 12, 0); cur[0] = 1;
    for (int i = 1; i <= max_x; i++) {
        if ((i * i <= 1000 && i != 1) || p[i].empty()) continue;
        for (auto [_, val] : p[i]) {
            auto nxt = cur;
            if (i != 1) _ |= 1 << 11;
            for (int s = 0; s < (1 << 12); s++) {
                int s_ = s ^ _;
                ll now = cur[s] * val % TT;
                int both = s & _;
                for (int j = 0; j < 11; j++)
                    if (both >> j & 1)
                        now = now * prime[j] % TT;
                if (both >> 11 & 1)
                    now = now * i % TT;
                nxt[s_] = (nxt[s_] + now) % TT;
            }
            cur = nxt;
        }
        for (int s = (1 << 11); s < (1 << 12); s++) cur[s] = 0;
    }
    ll ans = (cur[0] - 1 + TT) % TT;
    cout << ans << endl;
    return 0;
}