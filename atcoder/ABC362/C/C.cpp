#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("C.in", "r", stdin);
    int n; cin >> n;
    vector<ll> L(n + 1), R(n + 1);
    for (int i = 1; i <= n; i++) cin >> L[i] >> R[i];
    ll sum_L = 0, sum_R = 0;
    for (int i = 1; i <= n; i++) sum_L += L[i], sum_R += R[i];
    if (!(sum_L <= 0 && sum_R >= 0)) {
        cout << "No" << endl;
        return 0;
    }
    auto A = L;
    ll sum_A = sum_L;
    for (int i = 1; i <= n; i++) {
        if (sum_A < 0) {
            ll delta = min(R[i] - A[i], -sum_A);
            A[i] += delta;
            sum_A += delta;
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) cout << A[i] << " ";
    return 0;
}