#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int l, r; cin >> l >> r;
        if (l % 2 == 0) l += 1;
        if (r % 2 == 1) r += 1;
        int len = r - l + 1;
        cout << len / 4 << '\n';
    }
    return 0;
}