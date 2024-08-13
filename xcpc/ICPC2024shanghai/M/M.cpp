#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    if (n <= 2) {
        cout << "0\n";
        return 0;
    }
    int m = n / 2;
    cout << m << '\n';
    if (n & 1) {
        cout << 1 << ' ' << 2 << '\n';
        for (int i = 2; i + 2 <= n; i += 2)
            cout << i << ' ' << i + 2 << '\n';
        for (int i = 1; i + 2 <= n; i += 2)
            cout << i << ' ' << i + 2 << '\n';
    }else {
        int cnt = 0;
        for (int i = 1; i + 1 <= n; i++) {
            if (i == n / 2) continue;
            cout << i << ' ' << i + 1 << '\n';
            if (++cnt == m) break;
        }
        for (int i = 1; i <= n / 2; i++) {
            cout << i << ' ' << i + n / 2 << '\n';
        }
    }
    return 0;
}