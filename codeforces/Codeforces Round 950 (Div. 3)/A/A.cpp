#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for (auto c : s) 
        cnt[c - 'A']++;
    long long ans = 0;
    for (int i = 0; i < 7; i++)
        ans += max(m - cnt[i], 0);
    cout << ans << endl;
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}