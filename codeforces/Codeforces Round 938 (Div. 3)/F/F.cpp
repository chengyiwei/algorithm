#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(5);
    for (int i = 1; i <= 4; i++)
        cin >> a[i];
    int ans = 0;
    if ((a[1] & 1) && (a[2] & 1) && (a[3] & 1)) 
        ans = 1;
    for (int i = 1; i <= 4; i++)
        ans += a[i] / 2;
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}