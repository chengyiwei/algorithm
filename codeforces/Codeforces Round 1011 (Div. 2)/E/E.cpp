#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int vis[1000005];
constexpr int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i] - b[i];

    if (sum == 0) {
        if (a == b) {
            cout << INF << '\n';
            return;
        }
        else {
            cout << -1 << '\n';
 
            return;
        }
    }

    vector<ll> factors;
    for (ll i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            factors.push_back(i);
            if (i * i != sum) factors.push_back(sum / i);
        }
    }

    auto check = [&] (ll k) {
        // cout << k << '
        for (int i = 1; i <= n; i++) vis[a[i] % k] += 1;
        for (int i = 1; i <= n; i++) vis[b[i]] -= 1;
        int flg = 1;
        for (int i = 1; i <= n; i++) {
            if (vis[a[i] % k] != 0 or vis[b[i]] != 0) {
                flg = 0;
                break;
            }
        }
        for (int i = 1; i <= n; i++) vis[a[i] % k] = 0, vis[b[i]] = 0;
        return flg;
    };

    for (ll &k : factors) {
        if (check(k)) {
            cout << k << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    // freopen ("E.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}