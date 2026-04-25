#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    map<int, int> mp;
    for (int i = n - k + 1; i <= k; i++) mp[a[i]]++;

    for (int i = 1; i <= n; i++) {
        if (b[i] == -1) continue;
        if (i >= n - k + 1 && i <= k) {
            if (mp.count(b[i]) == 0 || mp[b[i]] == 0) {
                cout << "NO\n";
                return;
            }
            mp[b[i]]--;
        }
        else if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}