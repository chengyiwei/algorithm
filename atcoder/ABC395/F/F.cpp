#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, X; cin >> N >> X;
    vector<ll> D(N + 1), U(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> U[i] >> D[i];

    ll L = 1, R = 1e18, sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += D[i] + U[i];
        R = min(R, D[i] + U[i]);
    }
    R += 1;

    auto check = [&] (ll H) {
        ll L = max(0ll, H - D[1]), R = min(H, U[1]);
        if (L > R) return false;
        for (int i = 2; i <= N; i++) {
            ll pre_L = L, pre_R = R;
            L = max({0ll, H - D[i], pre_L - X});
            R = min({H, U[i], pre_R + X});
            if (L > R) return false;
        }
        return true;
    };

    while (L + 1 < R) {
        ll mid = (L + R) / 2;
        if (check(mid)) L = mid;
        else R = mid;
    }

    cout << L << "\n";

    cout << sum - L * N << '\n';
    return 0;
}