#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int x, y, z; cin >> x >> y >> z;
        int a, b, c; cin >> a >> b >> c;
        cout << max({a * x, b * y, c * z}) << endl;
    }
}