#include <bits/stdc++.h>
using namespace std;
const long long TT = 998244353;
int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int flg = 1;
        while (flg) {
            flg = 0;
            for (int i = n; i - 1 >= 1; i--) {
                if (a[i] > a[i - 1]) {
                    a[i] -= 1, a[i - 1] += 1;
                    flg = 1; break;
                }
            }
        }
        long long ans = 1;
        for (int i = 1; i <= n; i++) ans = (ans * a[i]) % TT;
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << '\n';
        cout << ans << '\n';
    }
}