#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;

double dis(pii A, pii B) {
    return sqrt(1.0 * (A.first - B.first) * (A.first - B.first) + 1.0 * (A.second - B.second) * (A.second - B.second));
}

void solve() {
    pii A, B;
    cin >> A.first >> A.second >> B.first >> B.second;
    auto C = A; C.first = -C.first;
    auto D = A; D.second = -D.second;
    double ans = min(dis(B, C), dis(B, D));
    cout << fixed << setprecision(10) << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}