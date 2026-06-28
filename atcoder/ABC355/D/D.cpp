#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<pii> a(n + 1);
    vector<int> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second, p.push_back(a[i].second), p.push_back(a[i].first);
    
    sort (p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for (int i = 1; i <= n; i++) {
        a[i].first = lower_bound(p.begin(), p.end(), a[i].first) - p.begin() + 1;
        a[i].second = lower_bound(p.begin(), p.end(), a[i].second) - p.begin() + 1;
    }
    
    vector<int> c(2 * n + 1, 0);
    auto add_x = [&] (int x, int val) {
        for (; x <= 2 * n; x += x & -x)
            c[x] += val;
    };

    auto query_x = [&] (int x) {
        int ret = 0;
        for (; x; x -= x & -x)
            ret += c[x];
        return ret;
    };

    function<long long (int, int)> cdq = [&] (int L, int R) {
        if (L >= R) return 0ll;
        int mid = (L + R) >> 1;
        ll ret = cdq(L, mid) + cdq(mid + 1, R);
        ll now = 0ll;
        for (int i = mid + 1; i <= R; i++)
            add_x (a[i].first, 1);
        for (int i = L; i <= mid; i++)
            now += query_x (a[i].second);
        for (int i = mid + 1; i <= R; i++)
            add_x (a[i].first, -1);
        return ret + now;
    };

    sort (a.begin() + 1, a.end());
    cout << cdq(1, n) << '\n';
    return 0;
}