#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int a[3] = {0};
    for (char c : s) a[c - '0'] += 1;

    if (n == k) {
        for (int i = 1; i <= n; i++)
            cout << '-';
        cout << '\n';
        return;
    }

    vector<char> res(n + 1, '+');
    for (int i = 1; i <= a[0]; i++)
        res[i] = '-';
    for (int i = n; i > n - a[1]; i--)
        res[i] = '-';

    for (int i = a[0] + 1; i <= a[0] + a[2]; i++) {
        if (res[i] == '+') res[i] = '?';
    }
    
    for (int i = n - a[1]; i > n - a[1] - a[2]; i--) {
        if (res[i] == '+') res[i] = '?';
    }

    for (int i = 1; i <= n; i++)
        cout << res[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}