#include <bits/stdc++.h>
using namespace std;
int solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> p;
    p.push_back(a[n]);
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] <= p.back()) {
            p.push_back(a[i]);
            continue;
        }
        int x = a[i];
        do {
            if (x % 10 > p.back()) {
                return 0;
            }
            p.push_back(x % 10);
            x /= 10;
        } while (x);
    }
    return 1;
}
int main() {
    freopen ("B.in", "r", stdin);
    int t; cin >> t;
    while (t--) 
        cout << (solve() ? "YES" : "NO") << '\n';
    return 0;
}