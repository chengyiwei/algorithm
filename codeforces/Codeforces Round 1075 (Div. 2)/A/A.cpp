#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h, l; cin >> n >> h >> l;
    if (h > l) swap(h, l);
    int cnth = 0, cntl = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= h) cnth += 1;
        if (a[i] <= l) cntl += 1;
    }
    cout << min(cntl / 2, cnth) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}