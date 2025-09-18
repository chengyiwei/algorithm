#include <bits/stdc++.h>
using namespace std;



int solve(int n) {
    for (int a = 1; a <= n; a++) {
        int b = n - a;
        if (b + (a / 2) != a) continue;
        else {
            return 1;
            for (int u = 1; u + 1 <= a; u += 1) {
                cout << u << " " << u + 1 << "\n";
            }
            for (int v = a + 1; v <= n; v++) {
                cout << 1 << " " << v << "\n";
            }
            // return ;
        }
    }
    return 0;
    solve(n - 1);
    cout << "2" << " " << n << "\n";
}

int main() {
    // freopen("G.in", "r", stdin);
    freopen ("G.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(nullptr);

    
    int lst = 1;
    for (int i = 1; i <= 10000; i++) {
        int now = solve(i);
        if (now == 0 && lst == 0){
            cout << "NO" << "\n";
            exit(0);
        }
        lst = now;
        cout << i << " : " << now << "\n";
    }
    return 0;

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n == 4 || n == 2) {
            cout << -1 << '\n';
        }
        else solve(n);
        // cout << '\n';
    }
    return 0;
}