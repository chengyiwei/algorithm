#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (y > -2)
            cout << "YES" << '\n';
        else 
            cout << "NO" << '\n';
    }
    return 0;
}