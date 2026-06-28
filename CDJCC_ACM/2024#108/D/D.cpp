#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> p(n, vector<int>());
    vector<int> T(n), K(n);
    for (int i = 0; i < n; i++) {
        cin >> T[i] >> K[i];
        for (int j = 0; j < K[i]; j++) {
            int x; cin >> x;
            p[i].push_back(x);
        }
    }
    vector<int> used(n, 0); used[n - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (used[i]) {
            for (int j = 0; j < K[i]; j++) {
                used[p[i][j] - 1] = 1;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) 
        ans += T[i] * used[i];
    cout << ans << endl;
    return 0;
}