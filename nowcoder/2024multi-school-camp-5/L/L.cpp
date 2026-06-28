#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll TT = 998244353;

void solve() {
    int n; cin >> n;
    ll sum = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    multiset<int> s;
    for (int i = n; i >= 1; i--) {
        while (true) {
            if ((!s.empty()) && a[i] < *s.rbegin()) {
                auto it = s.end(); --it;
                int x = *it;
                s.erase(it); x -= 1; a[i] += 1;
                s.insert(x);
            }
            else {
                s.insert(a[i]);
                break;
            }
        }
    }
    ll res = 1;
    for (auto x : s) res = res * x % TT;
    cout << res << '\n';
}

int main() {
    freopen ("L.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}