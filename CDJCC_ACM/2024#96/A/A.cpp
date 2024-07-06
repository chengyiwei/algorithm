#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    string s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;
    map<int, char> mp;
    for (int i = 0 ; i < n; i++) {
        if (mp.find(a[i]) == mp.end()) {
            mp[a[i]] = s[i];
        } else {
            if (mp[a[i]] != s[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}