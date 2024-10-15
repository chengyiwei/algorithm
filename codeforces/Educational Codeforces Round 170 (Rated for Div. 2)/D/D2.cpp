#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> v(n + 1);

    int ans = 0;

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int S = 0; S < (1 << m); S++) {
        int cnt = 0, ok = 0, A = 0, B = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i] == 0) {
                if (S >> cnt & 1) A += 1;
                else B += 1;
                cnt += 1;
            }
            if (v[i] > 0) {
                ok += A >= abs(v[i]);
            }
            if (v[i] < 0) {
                ok += B >= abs(v[i]);
            }
        }
        ans = max(ans, ok);
    }

    cout << ans << '\n';

    return 0;
}