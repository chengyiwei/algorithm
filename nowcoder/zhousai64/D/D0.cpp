#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[2][2];
    int T; cin >> T;
    while (T--) {
        cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
        int now = min(a[0][0] + a[1][1], a[0][1] + a[1][0]);
        if (now & 1) {
            cout << "kou" << '\n';
        }
        else 
            cout << "yukari" << '\n';
    }
}