#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    if (n & 1) {cout << "NO" << '\n'; return ;}
    cout << "YES" << '\n';
    for (int i = 1; i <= n / 2; i++ ){
        if (i & 1)
            cout << "AA";
        else 
            cout << "BB";
    }
    cout << '\n';

}
int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}