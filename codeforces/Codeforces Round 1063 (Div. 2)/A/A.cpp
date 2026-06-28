#include <bits/stdc++.h>
using namespace std;

void solve() {
        int n; cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a.begin() + 1, a.end());
        for (int i = 2; i + 1 <= n; i += 2) {
            if (a[i] != a[i + 1]) {
                cout << "No\n";
                return ;
            }
        }
        cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)  solve();
}