#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    int cnt_a = 0, cnt_b = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            if (a[i] > b[i]) cnt_a += a[i];
            else cnt_b += b[i];

    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == 0) continue;
            if (a[i] == 1) {
                if (cnt_a < cnt_b) cnt_a += 1;
                else cnt_b += 1;
            }
            if (a[i] == -1) {
                if (cnt_a > cnt_b) cnt_a -= 1;
                else cnt_b -= 1;
            }
        }
    }
    cout << min(cnt_a, cnt_b) << endl;
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}