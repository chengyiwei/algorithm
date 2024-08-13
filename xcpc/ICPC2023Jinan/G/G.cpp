#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 1e9 + 7;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

ll solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> fa(2 * n + 1);
    iota(fa.begin(), fa.end(), 0);
    auto find = [&] (auto &&find, int x) -> int {
        return x == fa[x] ? x : fa[x] = find(find, fa[x]);
    };
    auto merge = [&] (int x, int y) {
        x = find(find, x), y = find(find, y);
        if (x != y) fa[x] = y;
    };
    
    vector<int> idx(m + 1, 0), cnt(m + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            cnt[j] += a[i][j] == '1';
    for (int j = 0; j < m; j++) 
        if (cnt[j] + cnt[m - 1 - j] > 2)
            return 0ll;
    
    for (int i = 1; i <= n; i++) {
        auto s = a[i];
        for (int j = 0; j < m; j++) {
            if (s[j] == '0') continue;
            if (idx[j] == 0) idx[j] = i;
            else {
                int i_ = idx[j];
                merge(i, i_ + n);
                merge(i + n, i_);
            }
            if (idx[m - 1 - j] == 0) ;
            else {
                int i_ = idx[m - 1 - j];
                merge(i, i_);
                merge(i + n, i_ + n);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (find(find, i) == find(find, i + n))
            return 0ll;
    int cnt_ = 0;
    for (int i = 1; i <= n; i++)
        cnt_ += find(find, i) == i;
    return qpow(2, cnt_);
}

int main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) cout << solve() << '\n';
    return 0;
}