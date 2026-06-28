#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b; 
        while (a > 2) a -= 2; qwq
        while (b >= 2) b -= 2;
        if (a == 0 && b == 0) cout << "YES\n";
        else if (a == 2 && b == 0) cout << "YES\n";
        else if (a == 2 && b == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}