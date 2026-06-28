#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int m = *max_element(a.begin() + 1, a.end());
        for (int i = 1; i <= n; i++) {
            if (a[i] == m) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}