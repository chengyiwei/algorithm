
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; string s; cin >> n >> s;
    s = " " + s;

    vector<int> c(n + 5, 0);
    
    auto add_x = [&] (int x, int data) {
        for (int i = x; i <= n; i += i & -i) 
            c[i] += data;
    };

    auto get_x = [&] (int x) {
        int res = 0;
        for (int i = x; i; i -= i & -i) 
            res += c[i];
        return res;
    };

    auto check = [&] (int L) {
        fill (c.begin(), c.end(), 0);
        for (int i = 1; i + L - 1 <= n; i++) {
            int now = s[i] - '0';
            now ^= (get_x(i) & 1);
            if (now == 0) {
                add_x (i, 1);
                add_x (i + L, -1);
            }
        }
        for (int i = n - L + 1; i <= n; i++) {
            int now = s[i] - '0';
            now ^= (get_x(i) & 1);
            if (now == 0) return false;
        } 
        return true;
    };

    for (int L = n; L >= 1; L--) {
        if (check(L)) {
            cout << L << '\n';
            return;
        }
    }
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}