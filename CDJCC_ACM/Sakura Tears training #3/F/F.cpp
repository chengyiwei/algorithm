#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    int cnt = 1, sum = 1;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    set<int> s; s.insert(x);
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (x % a[i] != 0 || a[i] == 1) continue;
        vector<int> tmp;
        
    }
}

int main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}