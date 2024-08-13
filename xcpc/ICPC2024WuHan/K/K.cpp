#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    int x = n % 4;
    if (x == 0 || x == 1) puts("Fluttershy");
    else puts("Pinkie Pie");
}
int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}