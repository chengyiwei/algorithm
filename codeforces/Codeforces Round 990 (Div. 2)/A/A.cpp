#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x; sum += x;
            int sq = sqrt(sum);
            if (sq * sq == sum && sq % 2 == 1) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}