#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> t3;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<t3> p;
    for (int i = 1; i + 2 <= n; i++) {
        int x = a[i], y = a[i + 1], z = a[i + 2];
        p.emplace_back(x, y, z);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}