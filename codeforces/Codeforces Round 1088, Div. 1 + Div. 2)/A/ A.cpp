#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n == 1) {
            cout << "1\n";
        }
        else {
            for (int i = 1; i <= n; i++) cout << 2 << " \n"[i == n];
        }
    }
    return 0;
}