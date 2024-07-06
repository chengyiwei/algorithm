#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    char ch; cin >> ch;
    string s; cin >> s; s = s + s;
    int nxt = s.size() - 1;
    int ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'g')
            nxt = i;
        if (s[i] == ch)
            ans = max(ans, nxt - i);
    }
    cout << ans << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}