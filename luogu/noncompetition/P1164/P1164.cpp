#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    int M; cin >> M;
    vector<int> dp(M + 1, 0), a(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[M] << endl;
    return 0;
}