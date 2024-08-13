#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    string s[2];
    cin >> n;
    cin >> s[0] >> s[1];
    int fst = 0, lst = n;
    for (int i = 1; i < n; i++) {
        if (s[0][i] == '0' && s[1][i - 1] == '1') {
            fst = i;
        }
        if (s[0][i] == '1' && s[1][i - 1] == '0') {
            lst = i;
            break;
        }
    }
    string ans;
    int flg = 0;
    ans.push_back(s[0][0]);
    for (int i = 1; i < n; i++) {
        if (flg) {
            ans.push_back(s[1][i - 1]);
        }
        else {
            if (s[0][i] == '1' && s[1][i - 1] == '0') {
                flg = 1;
                ans.push_back(s[1][i- 1]);
            }
            else {
                ans.push_back(s[0][i]);
            }
        }
    }
    ans.push_back(s[1][n - 1]);
    cout << ans << '\n';
    cout << lst - fst << '\n';
}
int main() {
    freopen("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) solve();
}