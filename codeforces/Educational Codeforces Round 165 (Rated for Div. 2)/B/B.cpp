#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    vector<int> p;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == '0') p.push_back(i + 1);
    }
    int cnt = 0;
    ll ans = 0;
    for (auto pos: p) {
        cnt ++;
        if (pos != cnt)
            ans += pos - cnt + 1;
    }
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}