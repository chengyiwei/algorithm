#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        if (a >= b) {
            cout << a << '\n';
        }
        else {
            int c = b - a;
            cout << max(a - c, 0) << '\n';
        }
    }
    return 0;
}