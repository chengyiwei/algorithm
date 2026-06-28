#include <bits/stdc++.h>
using namespace std;

void solve() {
    array<int, 2> A, B;
    cin >> A[0] >> B[0] >> A[1] >> B[1];
    if (A[0] > B[0]) swap(A, B);
    if (A[1] >= B[1])
        cout << "NO" << '\n';
    else 
        cout << "YES" << '\n';

}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}