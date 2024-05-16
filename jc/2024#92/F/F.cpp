#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int min_x = *min_element(a.begin(), a.end());
    int cnt_min = count(a.begin(), a.end(), min_x);
    if (cnt_min == 1) {
        puts("YES");
        return ;
    }
    for (int &x : a) {
        if (x == min_x) continue;
        if (x % min_x != 0) {
            puts("YES");
            return ;
        }
    }
    puts("NO");
}

int main() {
    // freopen ("F.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}