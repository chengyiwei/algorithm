#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n + 1);
        int ans = 3;
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++) {
            if (i == p[p[i]]) {
                ans = 2;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}