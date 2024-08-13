#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p (n + 1, 1);
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        p[x] ^= 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += p[i];
    cout << ans << endl;
    return 0;
}