#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(const vector<ll>& a, const vector<ll>& d) {
    int n = a.size();
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    cout << sum << '\n';
    if (sum == 0) return 0;
    for (int i = 0; i < n; i++) {
        ll rd = (a[i] * 100 + sum / 2) / sum;
        // cout << rd << '\n';
        if (rd ^ d[i]) return 0;
    }
    return 1;
}

void print(vector<ll> a) {
    cout << "Yes\n";
    for (auto x : a) cout << x << " ";
    cout << "\n";
}



void solve() {
    int n; cin >> n;
    int cnt = 0;
    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        if (d[i] == 1) cnt ++;
    }

    if (cnt == 99) {
        cout << n << " ";
        for (int i = 0; i < n; i++) cout << d[i] << ' ';
        return ;
    }

    auto d_ = d;
    // if (check(d_, d)) { print(d_); return ; }

    // for (int i = 0; i < n; i++) d_[i] = max(d[i] * 2 - 1, 0ll);
    // if (check(d_, d)) { print(d_); return ; }


    // for (int i = 0; i < n; i++) d_[i] = max(d[i] * 2 + 1, 0ll);
    // if (check(d_, d)) { print(d_); return ; }


    for (int i = 0; i < n; i++) {
        d_[i] = max((d[i] * n / 1000 + 1) * 2 - 1, 0ll);
         cout << d_[i] << '\n';
    }
    if (check(d_, d)) { print(d_); return ; }

    cout << "No\n";
}

int main() {
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}