#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
    #define dprint(...)
    #define debug if constexpr (false)
#endif // LOCAL

void solve(int /* test_num */) {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> p(k, vector<int>(n));
    for (auto &v : p) {
        for (auto &x : v) {
            cin >> x;
            x--;
        }
    }

    vector<int> cuts;
    set<int> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            st.insert(p[j][i]);
        }
        if (len(st) == i + 1) {
            cuts.push_back(i);
        }
    }

    vector<int> comp(n), nxt(n), prev(n);
    for (int i = len(cuts) - 1; i >= 0; i--) {
        int p = (i == 0 ? -1 : cuts[i - 1]);
        for (int j = cuts[i]; j > p; j--) {
            comp[j] = cuts[i] - p;
            nxt[j] = cuts[i];
            prev[j] = p + 1;
        }
    }

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + comp[i];
    }

    ll ans = 0;
    while (q--) {
        int id, l, r;
        cin >> id >> l >> r;
        id = (id + ans) % k;
        l = (l + ans) % n;
        r = (r + ans) % n;
        r++;
        assert(l < r);

        ans = pref[r] - pref[l];
        ans -= r - l;

        {
            int pos = min(r - 1, nxt[l]);
            ans -= 1ll * (l - prev[l]) * (pos - l + 1);
        }
        {
            int pos = max(l, prev[r - 1]);
            ans -= 1ll * (nxt[r - 1] - r + 1) * (r - pos);
        }

        assert(ans % 2 == 0);
        ans /= 2;
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}
