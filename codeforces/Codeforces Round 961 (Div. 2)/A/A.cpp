#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (k == 0) return cout << 0 << '\n', void();
    vector<int> a;
    a.push_back(n);
    for (int i = n - 1; i >= 1; i--)
        a.push_back(i), a.push_back(i);
    for (int i = 1; ; i++) {
        if (a[i - 1] >= k) {
            cout << i << '\n';
            return;
        }
        k -= a[i - 1];
    }

}

int main() {
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();

} 