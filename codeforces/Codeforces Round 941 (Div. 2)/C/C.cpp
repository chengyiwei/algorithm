#include <bits/stdc++.h>
using namespace std;

string solve() {
    int m; cin >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin() + 1, a.end()), a.end());
    int n = a.size() - 1;
    vector<int> cf(n + 1, 0);
    int max_cf = 0;
    for (int i = 1; i <= n; i++) cf[i] = a[i] - a[i - 1], max_cf = max(max_cf, cf[i]);
    if (max_cf == 1) {
        if (n & 1) return "Alice";
        return "Bob";
    }
    for (int i = 1; i <= n; i++) {
        if (cf[i] > 1) {
            int x = i;
            if (x & 1) return "Alice";
            else return "Bob";
        }
    }
    return "Alice";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}