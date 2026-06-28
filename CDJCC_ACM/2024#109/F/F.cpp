#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> cnt(2005, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; cnt[x] = 1;
    }
    for (int i = 0; i <= 2000; i++) {
        if (cnt[i] == 0) {
            cout << i << '\n';
            return 0;
        }
    }
}