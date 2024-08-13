#include <bits/stdc++.h>
using namespace std;

bool solve() {
    string s; cin >> s;
    while (!s.empty()) {
        if (s.size() >= 5 && s.substr(0, 5) == "avava") s = s.substr(5);
        else if (s.size() >= 3 && s.substr(0, 3) == "ava") s = s.substr(3);
        else break;
    }
    return s.empty();
}

int main() {
    freopen ("K.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) cout << (solve() ? "Yes" : "No") << '\n';
    return 0;
}