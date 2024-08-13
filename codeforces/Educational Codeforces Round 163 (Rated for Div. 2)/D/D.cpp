#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s; cin >> s;;
    int ans = 0;
    for (int L = 1; L <= s.size() / 2; L++) {
        int i = 0, j = i + L;
        while (j + L - 1 < s.size()) {
            int ni = i, nj = j;

            while (ni < j) {
                if (s[ni] != '?' && s[nj] != '?' && s[ni] != s[nj]) break;
                ni++, nj++;
            }
            if (ni == j) {
                ans = max(ans, L * 2);
                break;
            }
            i = ni + 1, j = nj + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    freopen ("D.out", "w", stdout);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}