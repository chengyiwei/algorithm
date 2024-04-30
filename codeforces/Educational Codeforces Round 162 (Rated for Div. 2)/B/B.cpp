#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    map<int,int> mp;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++) {
        b[i] = abs(b[i]);
        if(mp.count(b[i])) mp[b[i]] += a[i];
        else mp[b[i]] = a[i];
    }
    int tim = 0, free = 0;
    for (auto &[pos,val] : mp){
        int free_tim = pos - tim;
        free += free_tim * k;
        if (free < val) {
            cout << "NO" << '\n';
            return;
        }
        free -= val;
        tim = pos;
    }
    cout << "YES" << '\n';
}

signed main() {
    freopen("B.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}