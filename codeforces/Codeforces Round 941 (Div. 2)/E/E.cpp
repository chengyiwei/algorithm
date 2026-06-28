#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int mx = 0, mn = 0, cur = 0;
    for (auto c : s) {
        if (((cur % 2 + 2) % 2) == (c == '1'))
            cur ++;
        else 
            cur --;
        mx = max(mx, cur);
        mn = min(mn, cur);
    }
    cout << mx - mn << '\n';

}

int main() {
    int t; cin >> t;
    while (t--) solve();
}