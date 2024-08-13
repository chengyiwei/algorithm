#include <bits/stdc++.h>
using namespace std;

bool calc(string a, string b) {
    if (a.size() != b.size()) return 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i] && a[i] != '?' && b[i] != '?') return 0;
    }
    return 1;
}

void solve() {
    string s; cin >> s;
    int ans = 0;
    for (int len = 2; len <= s.size(); len += 2) {
        for (int L = 0; L + len <= s.size(); L++) {
            int R = L + len - 1;
            int mid = (L + R) / 2;
            if (calc(s.substr(L, mid - L + 1), s.substr(mid + 1, R - mid))) {
                ans = max(ans, len);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    freopen ("D0.out", "w", stdout);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}