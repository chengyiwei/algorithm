#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    auto check_pre = [&] (string s, string t) -> bool {
        if (s.size() > t.size()) return false;
        if (s == t.substr(0, s.size())) return true;
        return false;
    };
    auto check_suf = [&] (string s, string t) -> bool {
        if (s.size() > t.size()) return false;
        if (s == t.substr(t.size() - s.size(), s.size())) return true;
        return false;
    };

    if (check_pre(s, t) && check_suf(s, t)) {
        cout << "0" << endl;
    } else if (check_pre(s, t)) {
        cout << "1" << endl;
    } else if (check_suf(s, t)) {
        cout << "2" << endl;
    } else {
        cout << "3" << endl;
    }
    return 0;
}