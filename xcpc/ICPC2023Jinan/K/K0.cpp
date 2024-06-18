
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int n; ll k; 
vector<ll> a;
ll sum_up = 0, sum_dn = 0;
ll mid = 0;
const ll TT = 1e9;
multiset<ll> up, dn;
void ins (ll x) {
    if (up.size() == 0 && dn.size() == 0 && mid == 0){
        mid = x; return ;
    }
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

void del (ll x) {
    if (x == mid) {
        if (dn.size() == 0 && up.size() == 0) {
            mid = 0; return ;
        }
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

void solve() {
    cin >> n >> k; a.resize(n + 1);    
    for (int i = 1; i <= n; i++)  cin >> a[i], a[i] = a[i] - i + 2 * TT + 1;
    int j = 1, ret = 0;
    up.clear(); dn.clear();
    sum_up = 0; sum_dn = 0; mid = 0;
    for (int i = 1; i <= n; i++) {
        while (j <= n) {
            ins(a[j]);
            ll now = (ll)((sum_up - mid * up.size()) + (mid * dn.size() - sum_dn));
            j += 1;
            if (now <= k) {
                ret = max(ret, j - i);
            }
            else 
                break;
        }
        del (a[i]);
    }
    cout << ret << endl;
    return ;
}

int main() {
    // freopen ("K.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    // cout << (double) clock() / CLOCKS_PER_SEC << endl;
    return 0;
}