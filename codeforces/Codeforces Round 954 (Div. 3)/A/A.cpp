#include <bits/stdc++.h>
using namespace std;
void solve() {
    vector<int> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = abs(a[0] - a[1]) + abs(a[2] - a[1]);
    cout << ans << endl;
}
int main() {
    int T; cin >> T;
    while (T--) solve();
}