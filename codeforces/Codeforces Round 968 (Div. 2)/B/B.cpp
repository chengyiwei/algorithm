#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a.begin() + 1, a.end());
        int pos = n / 2 + 1;
        cout << a[pos] << '\n';
    }
    return 0;
}