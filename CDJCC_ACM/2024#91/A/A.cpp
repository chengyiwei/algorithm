#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= 2 * n - 1; i += 2) {
        int x = i;
        if (x == 3) x = 2;
        if (x <= n) {
            printf ("%d %d\n", x, 1);
        }
        else {
            x = x - n + 1;
            printf ("%d %d\n", n, x);
        }
    }
    printf ("\n");  
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}