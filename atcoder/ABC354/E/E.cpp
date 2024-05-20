#include <bits/stdc++.h>
using namespace std;

int N;
const int maxn = 20;
int A[maxn], B[maxn];
int dp[1 << maxn];

int F(int S) {
    if (dp[S] != -1) return dp[S];
    for (int i = 0; i < N; i++) if (!(S >> i & 1)) {
        for (int j = i + 1; j < N; j++) if (!(S >> j & 1)) {
            if (A[i] != A[j] && B[i] != B[j]) continue;
            int S_ = S | (1 << i) | (1 << j);
            int now = F(S_);
            if (now == 0) return dp[S] = 1;
        }
    }
    return dp[S] = 0;
}

int main() {
    freopen ("E.in", "r", stdin);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    int res = F(0);
    if (res == 1) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}