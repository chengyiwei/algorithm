#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        vector<int> p;
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (x == 1) cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}