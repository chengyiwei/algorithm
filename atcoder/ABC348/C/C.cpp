#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    map<int, int> p;
    for (int i = 0; i < n; i++) {
        int A, C; cin >> A >> C;
        if (!p.count(C)) p[C] = A;
        else p[C] = min(p[C], A);
    }
    int ans = 0;
    for (auto [a, c] : p) ans = max(ans, c);
    cout << ans << '\n';
    return 0;
}