#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, X; cin >> n >> X;
    vector<int> A(n);
    for (int i = 0; i < n - 1; i++)
        cin >> A[i];
    for (int x = 0; x <= 100; x++) {
        auto B = A; B[n - 1] = x;
        sort(B.begin(), B.end());
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans += B[i];
        if (ans >= X) 
            return cout << x << '\n', 0;
    }
    cout << -1 << endl;
    return 0;
}