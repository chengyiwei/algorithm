#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i];
        cout << 2 * ((*max_element(a.begin(), a.end())) + (*max_element(b.begin(), b.end()))) << '\n';
    }
}