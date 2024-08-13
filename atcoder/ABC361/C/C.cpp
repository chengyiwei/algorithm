#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K; cin >> N >> K; K = N - K;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    sort(A.begin() + 1, A.end());
    int ans = 1e9;
    for (int i = 1; i + K - 1 <= N; i++) {
        ans = min(ans, A[i + K - 1] - A[i]);
    }
    cout << ans << endl;
    return 0;
}