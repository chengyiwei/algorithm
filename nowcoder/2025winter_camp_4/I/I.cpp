#include <bits/stdc++.h>
using namespace std;

//u*uwawauwa

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string t = "uwawauwa";
    int ans = 0;

    vector<int> pre(s.size(), 0);
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) pre[i] = (s[i] == 'u');
        else pre[i] = pre[i - 1] + (s[i] == 'u');
    }
    
    for (int i = 0; i + t.size() <= s.size(); i++) {
        bool ok = true;
        for (int j = 0; j < t.size(); j++) {
            if (t[j] != s[i + j]) {
                ok = false;
                break;
            }
        }
        if (ok == false) continue;
        ans += (i - 2 < 0 ? 0 : pre[i - 2]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}