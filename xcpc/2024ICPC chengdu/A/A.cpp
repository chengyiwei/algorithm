#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    if (s.size() < 5) {cout << "No\n"; return ;}
    if (s.substr(s.size() - 3, 3) != ">>>" || s.front() != '>') {cout << "No\n"; return ;}
    string t = s.substr(1, s.size() - 1 - 3);
    int flg = 0;
    for (auto c : t) if (c == '-') {flg = 1; break;}
    if (flg == 0) {cout << "No\n"; return ;}

    int pos = 0;
    for (int i = 1; i < s.size() - 3; i++) {
        if (s[i] == '-') pos = i;
    }
    

    vector<pair<int, int>> ans;

    for (int i = s.size() - 3; i > pos + 1; i--) {
        ans.push_back({1, i + 3 - 1 + 1});
    }

    for (int i = 0; i < pos; i++) {
        if (s[i] == '>')
            ans.push_back({i + 1, pos - i + 1 + 3});
    }

    cout << "Yes " << ans.size() << "\n";
    for (auto [x, l] : ans) cout << x << " " << l << '\n';

    return ;
}

int main() {
    // freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}