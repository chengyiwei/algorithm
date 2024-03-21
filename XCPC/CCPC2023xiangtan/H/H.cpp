#include <bits/stdc++.h>
using namespace std;
const int TT = 26;

int main() {
    freopen ("H.in","r",stdin);
    int n; cin >> n;
    string S, T; cin >> S >> T;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = ((T[i] - S[i]) % TT + TT) % TT;
    }
    int ans = 0;
    for (int i = n - 1; i > 0; i--) {
        if (a[i] != a[i - 1])
            ans ++;
    }
    if (a[0]) ans ++;
    cout << ans << endl;
    return 0;
}