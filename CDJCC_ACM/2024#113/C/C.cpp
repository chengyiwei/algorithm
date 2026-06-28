#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("C.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int sq = sqrt(n);
        string s; cin >> s; s = " " + s;
        if (sq * sq != n) {cout << "No\n"; continue;}
        int ok = 1;
        for (int k = 1; k <= n; k++) {
            int j = (k - 1) % sq + 1;
            int i = (k - 1) / sq + 1;
            if (i == 1 || i == sq || j == 1 || j == sq) {
                if (s[k] == '0') {cout << "No\n"; ok = 0;break;}
            }
            else if (s[k] == '1') {cout << "No\n"; ok = 0;break;}
        }
        if (ok) cout << "Yes\n";
    }
}