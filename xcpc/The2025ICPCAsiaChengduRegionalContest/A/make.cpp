#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n = 200000;
    cout << 1 << '\n' << n << '\n';
    for (int i = 0; i < n; i++) {
        if (i == 1) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
}