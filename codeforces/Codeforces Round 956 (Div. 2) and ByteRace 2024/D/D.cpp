#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 5;

int c[MAXN];

void add_x(int x) {
    for (int i = x; i < MAXN; i += i & -i)
        c[i] ^= 1;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= i & -i)
        res ^= c[i];
    return res;
}

int calc(vector<int> &a) {
    int n = a.size() - 1;
    int res = 0;
    for (int i = n; i; i--) {
        res ^= query(a[i]);
        add_x(a[i]);
    }
    for (int i = 1; i <= n; i++)
        add_x(a[i]);
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    auto a_ = a, b_ = b;
    sort(a_.begin(), a_.end()); sort(b_.begin(), b_.end());

    cout << ((a_ != b_) or (calc(a) ^ calc(b)) ? "NO" : "YES") << "\n";
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}