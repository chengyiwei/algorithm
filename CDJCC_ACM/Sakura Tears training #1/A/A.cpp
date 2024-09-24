#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int N, D; ll P; cin >> N >> D >> P;
    ll ans = inf;
    vector<ll> A(N + 1), S(N + 2, 0);
    for (int i = 1; i <= N; i++) {cin >> A[i];}
    sort (A.begin() + 1, A.end(), greater<ll>());
    for (int i = N; i >= 1; i--) {S[i] = S[i + 1] + A[i];}
    for (int j = 0;; j ++) {
        ll now = j * P + S[min(N + 1, j * D + 1)];
        ans = min(ans, now);
        if (j * D >= N) {break;}
    }
    cout << ans << endl;
    return 0;
}