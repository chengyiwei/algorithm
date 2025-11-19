#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    array<vector<int>, 3> p = {vector<int>(n + m), vector<int>(n + m), vector<int>(n + m)};
    for (int i = 0; i < n + m; i++) {
        cin >> p[0][i] >> p[1][i] >> p[2][i];
    }

    auto check = [&](vector<int> a) {
        sort(a.begin(), a.end());
        for (int i = 0, j = 0; i < n + m;) {
            while (j < n + m && a[j] == a[i]) j++;
            if ((j - i) % 2 != 0) return false;
            i = j;
        }
        return true;
    };

    if (check(p[0]) && check(p[1]) && check(p[2])) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}