#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int m; cin >> m;
    vector<int> d(m + 1);
    map<int, int> cnt;
    for (int i = 1; i <= m; i++) cin >> d[i], cnt[d[i]]++;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            if (!cnt.count(b[i]) || cnt[b[i]] == 0) {
                cout << "NO" << endl;
                return;
            }
            cnt[b[i]]--;
        }
    }
    cnt.clear();
    for (int i = 1; i <= n; i++) cnt[b[i]]++;
    if (!cnt.count(d[m])) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}