#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n), id(n);
    vector<int> c(n);

    auto add = [&] (int x, int val) {
        for (int i = x + 1; i <= n; i += i & -i) c[i - 1] += val;
    };

    auto query = [&] (int x) {
        int res = 0;
        for (int i = x; i; i -= i & -i) res += c[i - 1];
        return res;
    };
    
    auto get_sum = [&] (int l, int r) {
        return query(r) - query(l);
    };

    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i] -= 1;
        id[a[i]] = i;
    }

    vector  pre(n, vector<int>());
    for (int i = 0; i < n; i++) {
        int p = min(i, a[i] == 0 ? 0 : id[a[i] - 1] + 1);
        pre[p].push_back(a[i]);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto lst : pre[i]) add(lst, 1);
        add(a[i], -1);
        int now = get_sum(i == 0 ? 0 : a[i - 1] + 1, a[i]);
        ans += max(0, now);
    }
    cout << ans << '\n';
    return 0;
}