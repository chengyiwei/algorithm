#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int num = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] > a[i + 1])
            num += 1;
    }
    if (num == n - 1) return 0;
    return 1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}