#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    ll L = -1, R = 1e9;
    while (L + 1 < R) {
        auto check = [&] (ll mid) {
            vector<ll> need, have;
            for (int i = 1; i <= n; i++) {
                if (v[i] < mid) need.push_back(w[i] + mid);
                else have.push_back(w[i] + v[i]);
            }
            sort (need.begin(), need.end());
            sort (have.begin(), have.end());
            int j = 0;
            for (int i = 0; i < need.size(); i++) {
                while (j < have.size() && have[j] < need[i]) j++;
                if (j == have.size()) return false;
                j++;
            }
            return true;
        };

        ll mid = (L + R) >> 1;
        if (check(mid)) L = mid;
        else R = mid;
    } 
    cout << L << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
	ios::sync_with_stdio(false);
    cin.tie(0); 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}