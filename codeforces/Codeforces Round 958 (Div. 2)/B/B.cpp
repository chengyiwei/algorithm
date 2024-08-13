#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') p.push_back(1);
        if (s[i] == '0' && (i == 0 || s[i - 1] == '1')) p.push_back(0);
    }
    int cnt_0 = 0, cnt_1 = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == 0) cnt_0++;
        else cnt_1++;
    }
    if (cnt_1 > cnt_0)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}