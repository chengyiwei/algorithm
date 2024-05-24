#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(a.begin(), a.end(), i) - a.begin();
        cout << a[pos] - i << '\n';
    }
    return 0;
}