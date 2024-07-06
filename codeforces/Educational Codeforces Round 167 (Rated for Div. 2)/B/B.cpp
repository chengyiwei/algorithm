#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t; cin >> s >> t;
    int max_len = 0;
    for (int i = 0; i < t.size(); i++) {
        int pos = i;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == t[pos]) pos += 1;
            if (pos == t.size()) break;
        }
        max_len = max(max_len, pos - i);
    }
    cout << s.size() + t.size() - max_len << endl;
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve ();
    return 0;
}