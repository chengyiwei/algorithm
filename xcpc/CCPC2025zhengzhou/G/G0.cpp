#include <bits/stdc++.h>
using namespace std;



void solve(int n) {
    for (int a = 1; a <= n; a++) {
        int b = n - a;
        if (b + (a / 2) != a) continue;
        else {
            for (int u = 1; u + 1 <= a; u += 1) {
                cout << u << " " << u + 1 << "\n";
            }
            for (int v = a + 1; v <= n; v++) {
                cout << 1 << " " << v << "\n";
            }
            return ;
        }
    }
    solve(n - 1);
    cout << "2" << " " << n << "\n";
    return;
}

int main() {
    // freopen("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n == 4) {
            cout << -1 << '\n';
        }
        else solve(n);
        // cout << '\n';
    }
    return 0;
}