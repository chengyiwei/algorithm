#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
int main() {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = INF;
    for (int S = 0; S < (1 << n); S++) {
        long long A = 0, B = 0;
        for (int i = 0; i < n; i++) {
            if (S >> i & 1) A += a[i];
            else B += a[i];
        }
        ans = min(ans, max(A, B));
    }
    cout << ans << endl;
}