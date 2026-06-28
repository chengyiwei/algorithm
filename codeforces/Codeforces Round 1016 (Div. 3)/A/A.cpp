#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        if (x % 2 == 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}