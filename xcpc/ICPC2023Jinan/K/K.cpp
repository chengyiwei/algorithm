
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
void solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)  cin >> a[i], a[i] = a[i] - i;
    int L = 1, R = n + 1;

    auto check = [&] (int len) { 
        ll sum_up = 0, sum_dn = 0;
        multiset<ll> up, dn;
        ll mid, ret = inf;
        auto ins = [&] (ll x) {
            if (x >= mid) {
                up.insert(x); sum_up += x;
                if (up.size() > dn.size() + 1) {
                    dn.insert(mid); sum_dn += mid;
                    mid = *up.begin();
                    up.erase(up.begin()); sum_up -= mid;
                }
            }
            else  {
                dn.insert(x); sum_dn += x;
                if (dn.size() > up.size()) {
                    up.insert(mid); sum_up += mid;
                    auto it = dn.end(); --it;
                    mid = *it;
                    dn.erase(it); sum_dn -= mid;
                }
            }
            return ;
        };

        auto del = [&] (ll x) {
            if (x == mid) {
                if (dn.size() >= up.size()) {
                    auto it = dn.end(); --it;
                    mid = *it;
                    dn.erase(it); sum_dn -= mid;
                }
                else {
                    auto it = up.begin(); 
                    mid = *it;
                    up.erase(it); sum_up -= mid;
                }
            }
            else if (x > mid) {
                up.erase(up.find(x)); sum_up -= x;
                if (dn.size() > up.size()) {
                    up.insert(mid); sum_up += mid;
                    auto it = dn.end(); --it;
                    mid = *it;
                    dn.erase(it); sum_dn -= mid;
                }
            }else {
                dn.erase(dn.find(x)); sum_dn -= x;
                if (up.size() > dn.size() + 1) {
                    dn.insert(mid); sum_dn += mid;
                    mid = *up.begin();
                    up.erase(up.begin()); sum_up -= mid;
                }
            }
        };

        mid = a[1];
        for (int i = 2; i <= len; i++)
            ins(a[i]);
        ret = min(ret, (ll)((sum_up - mid * up.size()) + (mid * dn.size() - sum_dn)));
        for (int i = 1; i + len <= n; i++) {
            del (a[i]);
            ins (a[i + len]);
            ret = min(ret, (ll)((sum_up - mid * up.size()) + (mid * dn.size() - sum_dn)));
        }
        return ret;
    };

    while (L + 1 < R) {
        int mid = (R + L) >> 1;
        if (check (mid) <= k)
            L = mid;
        else 
            R = mid;
    }
    cout << L << endl;
    return ;
}

int main() {
    freopen ("K.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    cout << (double) clock() / CLOCKS_PER_SEC << endl;
    return 0;
}