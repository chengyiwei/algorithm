#include <bits/stdc++.h>
using namespace std;
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int L, R;
        cin >> L >> R;
        ans += 1ll * (R + L) * (R - L + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}