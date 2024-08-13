#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    string s[2];
    cin >> n;
    cin >> s[0] >> s[1];
    string ans;
    int flg = 0;
    ans.push_back(s[0][0]);
    for (int i = 1; i < n;i ++) {
        if (flg) {
            ans.push_back(s[1][i]);
            continue;
        }
        else {
            if (s[0][i] == s[1][i - 1]) {
                ans.push_back()
            }
        }
    }
    cout << ans << '\n';
    cout << F[1][n - 1] << '\n';
}
int main() {
    freopen("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) solve();
}