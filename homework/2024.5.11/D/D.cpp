#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;

ll f(int x) {
    if (x == 1) return k;
    return f(x - 1) + 1ll * n * (n - 1) / 2;
}


void solve() {
    cin >> n >> k;
    cout << f(n) << endl;
}

int main() {
    int T; cin >> T;
    while (T--) 
        solve();
}