#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<char> c(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == '.' && c[i - 1] != 'L' && c[i + 1] != 'L') c[i] = 'C';
    }
    for (int i = 1; i <= n; i++) {
        cout << c[i];
    }
    return 0;
}