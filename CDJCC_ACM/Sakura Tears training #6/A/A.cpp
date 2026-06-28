#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    vector<int> pre(N + 1, 0);
    vector<int> c(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        pre[i] = c[A[i]];
        c[A[i]] = i;
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += 1LL * (i - pre[i]) * (N + 1 - i);
    }
    cout << ans << '\n';
    return 0;
}