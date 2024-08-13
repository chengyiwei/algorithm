#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            string t = s;
            char c = s[i] == 'a' ? 'b' : 'a';
            t.insert(t.begin() + i, c);
            cout << t << '\n';
            return;
        }
    }
    char c = s[0] == 'a' ? 'b' : 'a';
    cout << c << s << '\n';
}

int main() {
    // freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}