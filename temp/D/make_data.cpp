#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("D.in", "w", stdout);
    srand(time(0));
    int n = 5e4;
    int m = 1e5;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        int len = rand() % 5 + 1;
        int l = rand() % (m) + 1;
        int r = l + len;
        cout << l << " " << r << '\n';
    }
}