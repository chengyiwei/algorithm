#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    int ans = 0, flg = 1;
    cin >> s;
    reverse(s.begin(), s.end());
    for (auto c : s) {
        if (c == '0') {
            ans += flg;
        }
        else {
            ans += 1;
            flg = 0;
        }
    }
    cout << ans - 1 << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}