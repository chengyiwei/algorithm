#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), s(n + 2);
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        a[i] = x - '0';
        s[i] = s[i - 1] + a[i];
    }
    
    int ans = -INF;
    for (int i = 0; i <= n; i++) { // 放在 i ~ i+1 之间
        int le_ok = i - s[i], ri_ok = s[n] - s[i];
        if (le_ok * 2 >= i && ri_ok * 2 >= (n - i)) {
            int x = i;
            if (abs(n  - i * 2) < abs(n - ans * 2)) 
                ans = i;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("C.in" ,"r", stdin);
    int t; cin >> t;
    while (t--) solve();
}