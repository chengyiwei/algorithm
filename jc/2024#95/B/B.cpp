#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    auto check = [&] (int len) {
        auto check_2 = [&] (string t) {
            int diff = 0;
            for (int i = 0; i < s.size(); i++) 
                if (s[i] != t[i % len]) diff++;
            if (diff <= 1) return true;
            return false;
        };

        if (check_2(s.substr(0, len)))return true;
        if (2 * len - 1 < s.size() && check_2(s.substr(len, 2 * len - 1))) return true;
        return false;
    };
    vector<int> fac;
    for (int i = 1; i * i <= s.size(); i++) {
        if (s.size() % i == 0) {
            fac.push_back(i);
            if (i * i != s.size()) fac.push_back(s.size() / i);
        }
    }
    int ans = 1e9;
    for (auto x : fac) {
        if (check(x)) ans = min(ans, x);
    }
    cout << ans << endl;
}

int main() {
    freopen ("B.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}