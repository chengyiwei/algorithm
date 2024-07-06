#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen ("A.in", "r", stdin);
    vector<int> p = {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000};
    vector<int> dp(1e5 + 1, 0);
    for (auto x : p) {
        dp[x] = 1;
    }
    for (int i = 0; i <= 1e5; i ++) {
        if (dp[i] == 0) continue;
        for (auto x : p) {
            if (i * x <= 1e5) {
                dp[i * x] |= dp[i];
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        cout << (dp[x] ? "YES" : "NO") << endl;
    }
    return 0;
}