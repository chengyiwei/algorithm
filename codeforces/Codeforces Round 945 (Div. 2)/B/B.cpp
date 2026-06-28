#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> pos;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1;
    for (int j = 0; j <= 20; j++) {
        bool flg = 0;
        for (int i = 1; i <= n; i++)
            flg |= (a[i] >> j & 1);
        if (!flg) continue;
        pos.clear();
        pos.push_back(0);
        for (int i = 1; i <= n; i++) 
            if (a[i] >> j & 1)
                pos.push_back(i);
        pos.push_back(n + 1);
        int now = 0;
        for (int i = 0; i + 1 < pos.size(); i++)
            now = max(now, pos[i + 1] - pos[i]);
        ans = max(ans, now);
    }
    cout << ans << endl;
}

int main() {
    freopen("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}