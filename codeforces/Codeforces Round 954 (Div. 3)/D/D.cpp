#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int string_to_int(string s) {
    int ret = 0;
    for (auto c : s)
        ret = ret * 10 + c - '0';
    return ret;
}

int check(vector<int> p) {
    if (*min_element(p.begin(), p.end()) == 0) return 0;
    int ret = 0;
    for (auto x : p)
        if (x != 1)
            ret += x;
    ret = max(ret, 1);
    return ret;
}

void solve() {
    int n; cin >> n;
    string s, t; cin >> s;
    vector<int> p;
    int ans = inf;
    for (int i = 0; i + 1 < n; i++) {
        p.clear();
        for (int j = 0; j < n;) {
            if (j == i)
                t = s.substr(j, 2), j += 2;
            else 
                t = s.substr(j, 1), j += 1;
            p.push_back(string_to_int(t));
        }
        ans = min(check(p), ans);
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}