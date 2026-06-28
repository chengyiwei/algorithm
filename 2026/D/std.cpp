#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> b(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        b[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}