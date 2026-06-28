#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen ("D.in", "r", stdin);
    int N, M, P; cin >> N >> M >> P;
    vector<int> A(N + 1, 0), B(M + 1, 0);
    vector<ll> sum_B(M + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++) 
        cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 1; i <= M; i++)
        sum_B[i] = sum_B[i - 1] + B[i];
    
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] > P) {
            ans += 1ll * P * M;
            continue;
        }
        auto it = upper_bound (B.begin(), B.end(), P - A[i]); --it;
        int j = it - B.begin();
        ans += sum_B[j] + 1ll * j * A[i]; 
        ans += 1ll * (M - j) * P;
    }
    cout << ans << endl;
    return 0;
}