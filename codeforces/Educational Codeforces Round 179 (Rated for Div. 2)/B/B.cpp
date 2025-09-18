#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> f(n + 1, 0);
    f[1] = 1; f[2] = 2;
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    while (m--) {
        array<int, 3> query;
        cin >> query[0] >> query[1] >> query[2];
        sort(query.begin(), query.end());
        int a = query[0], b = query[1], c = query[2];
        // cout << "Query: " << a << " " << b << " " << c << "\n";
        // cout << f[n] << " " << f[n - 1] << "\n";
        if (a >= f[n] && c >= f[n] + f[n - 1])
            cout << 1;
        else 
            cout << 0;
        
    }
    cout << "\n";
}

int main() {
    // freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}