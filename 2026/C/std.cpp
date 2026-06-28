#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve() {
    int x;
    cin >> x;
    string s;
    for (int i = 1; s.size() < x; i++) {
        s += to_string(i);
    }
    cout << s[x - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}