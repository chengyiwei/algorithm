#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    if (m == n - 2) {cout << -1 << '\n'; return;}
    int p = n - m;
    vector<int> res(n + 1, 0);
    int l = 1, r = p;
    for (int i = p - 0; i >= 1; i -= 3) res[i] = r--;
    for (int i = p - 1; i >= 1; i -= 3) res[i] = r--;
    for (int i = p - 2; i >= 1; i -= 3) res[i] = l++;
    for (int i = p + 1; i <= n; i++) res[i] = i;
    for (int i = 1; i <= n; i++) cout << res[i] << " \n"[i == n];
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}