#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pil;
void solve() {
    int n; ll k; cin >> n >> k;
    ll now = 0;
    vector<pil> a(n + 1, {0,0});
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        now += k * (a[i].first - a[i - 1].first);
        now -= a[i].second;
        if (now < 0) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
}
int main() {
    freopen ("A.in" ,"r", stdin);
    int t; cin >> t;
    while (t--) solve();
}