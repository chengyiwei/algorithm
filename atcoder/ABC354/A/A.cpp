#include <bits/stdc++.h>
using namespace std;
int main() {
    typedef long long ll;
    ll n; cin >> n;
    ll H = 0;
    for (int i = 0; i <= 30; i++) {
        if (H > n) {
            cout << i << endl;
            return 0;
        }
        H += (1ll << i);
    }
}